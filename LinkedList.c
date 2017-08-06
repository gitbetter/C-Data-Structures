/*                              ___           ___           ___          _____                                    ___
                  ___          /__/\         /__/|         /  /\        /  /::\                     ___          /  /\          ___
                 /  /\         \  \:\       |  |:|        /  /:/_      /  /:/\:\                   /  /\        /  /:/_        /  /\
  ___     ___   /  /:/          \  \:\      |  |:|       /  /:/ /\    /  /:/  \:\   ___     ___   /  /:/       /  /:/ /\      /  /:/
 /__/\   /  /\ /__/::\      _____\__\:\   __|  |:|      /  /:/ /:/_  /__/:/ \__\:| /__/\   /  /\ /__/::\      /  /:/ /::\    /  /:/
 \  \:\ /  /:/ \__\/\:\__  /__/::::::::\ /__/\_|:|____ /__/:/ /:/ /\ \  \:\ /  /:/ \  \:\ /  /:/ \__\/\:\__  /__/:/ /:/\:\  /  /::\
  \  \:\  /:/     \  \:\/\ \  \:\~~\~~\/ \  \:\/:::::/ \  \:\/:/ /:/  \  \:\  /:/   \  \:\  /:/     \  \:\/\ \  \:\/:/~/:/ /__/:/\:\
   \  \:\/:/       \__\::/  \  \:\  ~~~   \  \::/~~~~   \  \::/ /:/    \  \:\/:/     \  \:\/:/       \__\::/  \  \::/ /:/  \__\/  \:\
    \  \::/        /__/:/    \  \:\        \  \:\        \  \:\/:/      \  \::/       \  \::/        /__/:/    \__\/ /:/        \  \:\
     \__\/         \__\/      \  \:\        \  \:\        \  \::/        \__\/         \__\/         \__\/       /__/:/          \__\/
                               \__\/         \__\/         \__\/                                                 \__\/


     LinkedList.h
     Created by Adrian Sanchez
     Created on 07/02/2017
*/

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


#include "LinkedList.h"

boolean LinkedList_New(LinkedList *list) {
    list->head = (ListNode *) malloc(sizeof(ListNode));
    list->head = NULL;

    return TRUE;
}

void LinkedList_Free(LinkedList *list) {
    if(!list || !list->head)
        return;

    ListNode *p;
    while(list->head != NULL) {
        p = list->head;
        list->head = list->head->next;
        free(p);
    }
    free(list);
}

boolean LinkedList_isEmpty(LinkedList *list) {
    return list->head == NULL;
}

size_t LinkedList_GetSize(LinkedList *list) {
    if(!list)
        return 0;

    size_t size = 0;
    for(ListNode *p = list->head; p != NULL; p = p->next, size++) ;
    return size;
}

boolean LinkedList_InsertAfter(ListNode *node, void *item) {
    ListNode *newNode;
    if(!(newNode = (ListNode *) malloc(sizeof(ListNode))))
        return FALSE;

    newNode->data = item;
    newNode->prev = node;
    newNode->next = node->next;
    node->next = newNode;

    return TRUE;
}

boolean LinkedList_InsertBefore(ListNode *node, void *item) {
    ListNode *newNode;
    if(!(newNode = (ListNode *) malloc(sizeof(ListNode))))
        return FALSE;

    newNode->data = item;
    newNode->next = node;
    newNode->prev = node->prev;
    node->prev = newNode;

    return TRUE;
}

boolean LinkedList_InsertBeginning(LinkedList *list, void *item) {
    ListNode *newNode;
    if(!(newNode = (ListNode *) malloc(sizeof(ListNode))))
        return FALSE;

    newNode->data = item;

    newNode->next = list->head;
    if(newNode->next != NULL)
        newNode->next->prev = newNode;
    
    newNode->prev = NULL;
    list->head = newNode;

    return TRUE;
}

boolean LinkedList_InsertEnd(LinkedList *list, void *item) {
    ListNode *newNode;
    if(!(newNode = (ListNode *) malloc(sizeof(ListNode))))
        return FALSE;

    newNode->data = item;
    newNode->next = NULL;

    if(list->head == NULL) {
        list->head = newNode;
        newNode->prev = NULL;
    } else {
        ListNode *p;
        for(p = list->head; p->next != NULL; p = p->next);
        p->next = newNode;
        newNode->prev = p;
    }

    return TRUE;
}

void *LinkedList_Remove(LinkedList *list, void *item) {
    if(!list || !list->head)
        return NULL;

    ListNode *p = list->head;
    while(p->data != item) {
        if(p->next == NULL)
            return NULL;
        p = p->next;
    }

    void *removed = p->data;
    if(p->prev == NULL) {
        LinkedList_RemoveFirst(list);
    } else if(p->next == NULL) {
        LinkedList_RemoveLast(list);
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }

    return removed;
}

void *LinkedList_RemoveFirst(LinkedList *list) {
    if(!list || !list->head)
        return NULL;

    void *removed = list->head->data;
    ListNode *after = list->head->next;
    free(list->head);
    list->head = after;


    return removed;
}

void *LinkedList_RemoveLast(LinkedList *list) {
    if(!list || !list->head)
        return NULL;

    if(!list->head->next) {
        void *removed = list->head->data;
        free(list->head);
        list->head = NULL;
        return removed;
    }

    ListNode *p;
    for(p = list->head; p->next != NULL; p = p->next) ;

    void *removed = p->data;
    p->prev->next = NULL;
    free(p);

    return removed;
}

LinkedList *LinkedList_toList(void **items, size_t n) {
    LinkedList *list;
    if(!(list = (LinkedList *) malloc(sizeof(LinkedList))))
        return NULL;

    if(!LinkedList_New(list))
        return NULL;

    for(int i = 0; i < n; i++)
        LinkedList_InsertEnd(list, items[i]);

    return list;
}

void **LinkedList_toArray(LinkedList *list) {
    if(!list)
        return NULL;

    size_t list_size = LinkedList_GetSize(list);
    void **p = (void **) malloc(list_size * sizeof(void *) + 1);

    int i = 0;
    for(ListNode *curr = list->head; curr->next != NULL; curr = curr->next)
        p[i++] = curr->data;

    return p;
}

boolean LinkedList_Contains(LinkedList *list, void *item) {
    if(!list || !list->head)
        return FALSE;

    for(ListNode *p = list->head; p != NULL; p = p->next)
        if(p->data == item)
            return TRUE;

    return FALSE;
}

void *LinkedList_ItemAtIndex(LinkedList *list, size_t index) {
    if(!list || !list->head)
        return NULL;

    size_t list_size = LinkedList_GetSize(list);
    if(index > list_size)
        return NULL;

    ListNode *p = list->head;
    for(int i = 0; i < list_size; i++) {
        if(i == index)
            return p->data;
        p = p->next;
    }

    return NULL;
}

void ListNode_Print(ListNode *node) {
    if(node)
        printf("[node] = %p\n", node->data);
}

void LinkedList_Print(LinkedList *list) {
    ListNode *node;
    int index = 0;
    for(node = list->head; node != NULL; node = node->next) {
        if(!node->next)
            printf("[node %d] = %p\n", index++, node->data);
        else
            printf("[node %d] = %p, ", index++, node->data);
    }
}



/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
