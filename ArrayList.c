 /*   ___           ___           ___           ___                                                 ___
     /  /\         /  /\         /  /\         /  /\          ___                     ___          /  /\          ___
    /  /::\       /  /::\       /  /::\       /  /::\        /__/|                   /  /\        /  /:/_        /  /\
   /  /:/\:\     /  /:/\:\     /  /:/\:\     /  /:/\:\      |  |:|    ___     ___   /  /:/       /  /:/ /\      /  /:/
  /  /:/~/::\   /  /:/~/:/    /  /:/~/:/    /  /:/~/::\     |  |:|   /__/\   /  /\ /__/::\      /  /:/ /::\    /  /:/
 /__/:/ /:/\:\ /__/:/ /:/___ /__/:/ /:/___ /__/:/ /:/\:\  __|__|:|   \  \:\ /  /:/ \__\/\:\__  /__/:/ /:/\:\  /  /::\
 \  \:\/:/__\/ \  \:\/:::::/ \  \:\/:::::/ \  \:\/:/__\/ /__/::::\    \  \:\  /:/     \  \:\/\ \  \:\/:/~/:/ /__/:/\:\
  \  \::/       \  \::/~~~~   \  \::/~~~~   \  \::/         ~\~~\:\    \  \:\/:/       \__\::/  \  \::/ /:/  \__\/  \:\
   \  \:\        \  \:\        \  \:\        \  \:\           \  \:\    \  \::/        /__/:/    \__\/ /:/        \  \:\
    \  \:\        \  \:\        \  \:\        \  \:\           \__\/     \__\/         \__\/       /__/:/          \__\/
     \__\/         \__\/         \__\/         \__\/                                               \__\/


     ArrayList.m
     Created by Adrian Sanchez
     Created on 07/02/2017
*/

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


#include "ArrayList.h"

void listncpy(void **dest, void **src, size_t num);
void repopulate(ArrayList *list);
boolean alresize(ArrayList *list, size_t new_size);

/*
 * Initialize a new ArrayList with a size and capacity (reserved)
 * and allocate memory for internal array
 */
boolean ArrayList_New(ArrayList * list) {
    list->size = 0;
    list->reserved = INITIAL_SIZE_STRING_LIST;
    if((list->arr = (void *) calloc(INITIAL_SIZE_STRING_LIST, sizeof(void *))))
        return TRUE;

    //repopulate(list->arr);

    return FALSE;
}

/*
 * Expands the ArrayList by doubling the capacity if the current list size
 * exceeds the maximum capacity
 */
boolean ArrayList_Expand(ArrayList * list) {
    if(list->size < list->reserved)
        return FALSE;

    list->reserved *= 2;
    if((list->arr = (void *) realloc(list->arr, list->reserved)))
        return TRUE;
    return FALSE;
}

/*
 * Add a new ArrayList item, expanding the list if needed
 * (ideally should call ArrayList_Compact, as we might unwittingly
 * write over an element in a sparse ArrayList since size increase linearly)
 */
boolean ArrayList_Add(ArrayList * list, void * item) {
    if(list->size == list->reserved && !ArrayList_Expand(list))
        return FALSE;

    list->arr[list->size++] = item;
    return TRUE;
}

/*
 * Return a pointer to the structure's internal list
 */
void * ArrayList_GetList(ArrayList * list) {
    return list->arr;
}

/*
 * Simply return the list size
 */
inline size_t ArrayList_GetSize(ArrayList * list) {
    return list->size;
}

/*
 * Free up an ArrayList structure in memory, also
 * freeing up the internal list if needed
 */
void ArrayList_Free(ArrayList * list) {
    if(list) {
        if(list->arr) free(list->arr);
        list->arr = NULL;
        free(list);
    }
}

/*
 * Remove the element of the ArrayList at position index
 */
boolean ArrayList_Remove(ArrayList * list, size_t index) {
    if(index > list->reserved)
        return FALSE;

    void **new = (void **) calloc(list->reserved, sizeof(void *));
    listncpy(new, list->arr, list->reserved);
    if(!new)
        return FALSE;

    free(list->arr);
    list->arr = (void **) calloc(list->reserved, sizeof(void *));
    //repopulate(list->arr);

    int j = 0;
    for(int i = 0; i < list->reserved; i++)
        if(i != index)
            list->arr[j++] = new[i];

    list->size--;

    free(new);

    return TRUE;
}

/*
 * Remove the last element of the ArrayList
 */
boolean ArrayList_RemoveLast(ArrayList *list) {
    if(list && list->size)
        return ArrayList_Remove(list, list->size - 1);

    return FALSE;
}

/*
 * Place void *item at the index position of the provided ArrayList,
 * and expand the array if needed. Note that the ArrayList allows sparse
 * distribution.
 */
boolean ArrayList_Set(ArrayList *list, size_t index, void * item) {
    if(index > list->reserved) {
        size_t new_reserved = list->reserved * (size_t) index / list->reserved + (index % list->reserved != 0 ? 1 : 0);
        ArrayList_ExpandReserved(list, new_reserved);
    }

    if(!list->arr[index]) list->size++;         // If no element exists at this index, increase the list size
    list->arr[index] = item;

    return TRUE;
}

/*
 * Return a pointer to the item at position index of ArrayList,
 * or NULL if the index is out of bounds
 */
void *ArrayList_Get(ArrayList *list, size_t index) {
    if(index > list->reserved)
        return NULL;

    return list->arr[index];
}

/*
 * Clear and compact the ArrayList
 */
boolean ArrayList_Clear(ArrayList * list) {
    list->size = 0;
    return ArrayList_Compact(list);
}

/*
 * Copy the contents of ArrayList *source to ArrayList *destination
 */
boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source) {
    destination->arr = (void *) realloc(destination->arr, source->reserved);
    if(!destination->arr)
        return FALSE;

    destination->size = source->size;
    destination->reserved = source->reserved;
    listncpy(destination->arr, source->arr, source->reserved);
    return TRUE;
}

/*
 * Expand the reserved list space (capacity) by to the provided reserved parameter,
 * only if the new reserved size is greater than the existing reserved size
 */
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved) {
    if(reserved < list->reserved)
        return FALSE;

    return alresize(list, reserved);
}

/*
 * Condenses the ArrayList down to the size of the list + initial reserved space.
 * This function is great if you have a sparse ArrayList and want to utilize memory
 * more efficiently
 */
boolean ArrayList_Compact(ArrayList * list) {
    size_t new_reserved = list->size + INITIAL_SIZE_STRING_LIST;

    return alresize(list, new_reserved);
}

/*
 * Print the contents (pointers) of the ArrayList as they are found
 */
void ArrayList_Print(ArrayList *list) {
    int j = 0;
    for(int i = 0; i < list->reserved; i++) {
        void *p = ArrayList_Get(list, i);
            if(p) {
                if(j++ == list->size - 1)
                    printf("[%d] = %p\n", i, p);
                else
                    printf("[%d] = %p, ", i, p);
            }
    }
}

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


/* /$$   /$$ /$$$$$$$$ /$$       /$$$$$$$  /$$$$$$$$ /$$$$$$$   /$$$$$$
  | $$  | $$| $$_____/| $$      | $$__  $$| $$_____/| $$__  $$ /$$__  $$
  | $$  | $$| $$      | $$      | $$  \ $$| $$      | $$  \ $$| $$  \__/
  | $$$$$$$$| $$$$$   | $$      | $$$$$$$/| $$$$$   | $$$$$$$/|  $$$$$$
  | $$__  $$| $$__/   | $$      | $$____/ | $$__/   | $$__  $$ \____  $$
  | $$  | $$| $$      | $$      | $$      | $$      | $$  \ $$ /$$  \ $$
  | $$  | $$| $$$$$$$$| $$$$$$$$| $$      | $$$$$$$$| $$  | $$|  $$$$$$/
  |__/  |__/|________/|________/|__/      |________/|__/  |__/ \______/*/


void listncpy(void **dest, void **src, size_t num) {
    for(int i = 0; i < num; i++)
        dest[i] = src[i];
}

void repopulate(ArrayList *list) {
    for(int i = 0; i < list->reserved; i++)
        list->arr[i] = NULL;
}

boolean alresize(ArrayList *list, size_t new_size) {
    
    void **new = (void **) calloc(new_size, new_size * sizeof(void *));
    listncpy(new, list->arr, list->reserved);
    if(!new)
        return FALSE;
    
    free(list->arr);
    list->arr = (void *) calloc(new_size, new_size * sizeof(void *));
    
    if(list->size > 0) {                // Make sure arraylist contains items and copy accordingly
        int j = 0;
        for(int i = 0; i < list->reserved; i++)
            if(new[i])
                list->arr[j++] = new[i];
    }
    
    free(new);
    
    list->reserved = new_size;
    
    return TRUE;
}


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
