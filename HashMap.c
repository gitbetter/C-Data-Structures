/*    ___           ___           ___           ___           ___           ___           ___
     /__/\         /  /\         /  /\         /__/\         /__/\         /  /\         /  /\
     \  \:\       /  /::\       /  /:/_        \  \:\       |  |::\       /  /::\       /  /::\
      \__\:\     /  /:/\:\     /  /:/ /\        \__\:\      |  |:|:\     /  /:/\:\     /  /:/\:\
  ___ /  /::\   /  /:/~/::\   /  /:/ /::\   ___ /  /::\   __|__|:|\:\   /  /:/~/::\   /  /:/~/:/
 /__/\  /:/\:\ /__/:/ /:/\:\ /__/:/ /:/\:\ /__/\  /:/\:\ /__/::::| \:\ /__/:/ /:/\:\ /__/:/ /:/
 \  \:\/:/__\/ \  \:\/:/__\/ \  \:\/:/~/:/ \  \:\/:/__\/ \  \:\~~\__\/ \  \:\/:/__\/ \  \:\/:/
  \  \::/       \  \::/       \  \::/ /:/   \  \::/       \  \:\        \  \::/       \  \::/
   \  \:\        \  \:\        \__\/ /:/     \  \:\        \  \:\        \  \:\        \  \:\
    \  \:\        \  \:\         /__/:/       \  \:\        \  \:\        \  \:\        \  \:\
     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/

     HashMap.m
     Created by Adrian Sanchez
     Created on 07/02/2017
*/
/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


#include <math.h>
#include "globalconst.h"
#include "HashMap.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "String.h"

size_t hash(const char *key, size_t t_size);
size_t hash(const char *key, size_t t_size);
size_t nextprime(size_t num);
boolean isprime(size_t num);


boolean HashMap_New(HashMap *map) {
    map->size = 0;
    map->table = (ArrayList *) malloc(sizeof(ArrayList));
    if(!ArrayList_New(map->table))
        return FALSE;

    ArrayList_ExpandReserved(map->table, INITIAL_NUM_BUCKETS);
    for(int i = 0; i < INITIAL_NUM_BUCKETS; i++) {
        map->table->arr[i] = (LinkedList *) malloc(sizeof(LinkedList));
        if(!LinkedList_New(map->table->arr[i])) {
            ArrayList_Free(map->table);
            return FALSE;
        }
    }

    return TRUE;
}

void HashMap_Free(HashMap *map) {
    if(!map)
        return;

    size_t num_buckets = map->table->reserved;
    int i;
    for(i = 0; i < num_buckets; i++) {
        LinkedList *ll = ArrayList_Get(map->table, i);
        MapEntry *entry;
        while((entry = LinkedList_RemoveLast(ll)))
            HashEntry_Free(entry);

        LinkedList_Free((LinkedList *) ArrayList_Get(map->table, i));
    }

    ArrayList_Free(map->table);
    free(map);
}

size_t HashMap_GetSize(HashMap *map) {
    return (size_t) map->size;
}

boolean HashMap_Set(HashMap *map, char *key, void *value) {
    if(HashMap_Get(map, key) == value)
        return FALSE;

    // Decrease the load factor when number of elements exceeds number of buckets
    size_t num_buckets = map->table->reserved;
    double load_factor = ++(map->size) / (double) num_buckets;
    if(load_factor > 1.0) {
        double mult = map->size / ((double) num_buckets * 0.75);
        HashMap_Expand(map, (size_t) nextprime(num_buckets * mult));
        num_buckets = map->table->reserved;
    }

    size_t hashed = hash(key, num_buckets);
    LinkedList *bucket = (LinkedList *) ArrayList_Get(map->table, hashed);

    MapEntry *entry = (MapEntry *) malloc(sizeof(MapEntry));

    entry->key = (String *) malloc(sizeof(String));
    String_New(entry->key, key);
    entry->value = value;

    if(HashMap_Get(map, key) != NULL)
        HashMap_Remove(map, key);

    LinkedList_InsertBeginning(bucket, entry);

    return TRUE;
}

MapEntry *HashMap_GetEntry(HashMap *map, char *key) {
    size_t hashed = hash(key, map->table->reserved);
    LinkedList *bucket = (LinkedList *) ArrayList_Get(map->table, hashed);
    size_t bucket_size = LinkedList_GetSize(bucket);

    for(int i = 0; i < bucket_size; i++) {
        MapEntry *ent = LinkedList_ItemAtIndex(bucket, i);
        if(!ent) continue;

        String *check_key = (String *) malloc(sizeof(String));
        String_New(check_key, key);

        if(String_Equal(ent->key, check_key)) {
            String_Free(check_key);
            return ent;
        }

        String_Free(check_key);
    }

    return NULL;
}

void *HashMap_Get(HashMap *map, char *key) {
    MapEntry *ent;
    if((ent = HashMap_GetEntry(map, key)) != NULL)
        return ent->value;

    return NULL;
}

void *HashMap_Remove(HashMap *map, char *key) {
    size_t hashed = hash(key, map->table->reserved);
    LinkedList *bucket = (LinkedList *) ArrayList_Get(map->table, hashed);

    MapEntry *ent;
    if((ent = HashMap_GetEntry(map, key)) != NULL) {
        void *val = ent->value;
        LinkedList_Remove(bucket, ent);
        HashEntry_Free(ent);
        map->size--;
        return val;
    }

    return NULL;
}

boolean HashMap_Clear(HashMap *map) {
    if(!map)
        return FALSE;

    map->size = 0;

    size_t buckets = map->table->reserved;
    for(int i = 0; i < buckets; i++) {
        MapEntry *entry;
        while((entry = (MapEntry *) LinkedList_RemoveLast((LinkedList *) ArrayList_Get(map->table, i))))
            HashEntry_Free(entry);

        LinkedList_Free((LinkedList *) ArrayList_Get(map->table, i));
    }

    if(!(ArrayList_Clear(map->table)))
        return FALSE;

    ArrayList_ExpandReserved(map->table, INITIAL_NUM_BUCKETS);
    for(int i = 0; i < INITIAL_NUM_BUCKETS; i++) {
        LinkedList *p = (LinkedList *) malloc(sizeof(LinkedList));
        if(!LinkedList_New(p) || !ArrayList_Add(map->table, p))
            return FALSE;
    }

    return TRUE;
}

boolean HashMap_Expand(HashMap *map, size_t new_size) {
    if(!map)
        return FALSE;

    HashMap *old = (HashMap *) malloc(sizeof(HashMap));
    *old = *map;

    HashMap_Clear(map);
    ArrayList_ExpandReserved(map->table, new_size);

    size_t old_size = old->table->reserved;
    for(int i = 0; i < old_size; i++) {
        LinkedList *llist = (LinkedList *) ArrayList_Get(old->table, i);
        for(ListNode *node = llist->head; node != NULL; node = node->next) {
            MapEntry *entry = (MapEntry *) node->data;
            HashMap_Set(map, String_Get(entry->key), entry->value);
        }
    }

    HashMap_Free(old);

    return TRUE;
}

boolean HashEntry_Free(MapEntry *entry) {
    if(entry) {
        if(entry->key) String_Free(entry->key);
        free(entry);
        return TRUE;
    }

    return FALSE;
}

void HashMap_Print(HashMap *map) {
    size_t alist_size = map->table->reserved;

    printf("{");
    
    int j = 0;
    for(int i = 0; i < alist_size; i++) {
        LinkedList *llist = (LinkedList *) ArrayList_Get(map->table, i);
        for(ListNode *node = llist->head; node != NULL; node = node->next) {
            MapEntry *entry = node->data;
            if(entry && entry->key) {
                if(j++ == map->size - 1)
                    printf("[%s] = %p", String_Get(entry->key), entry->value);
                else
                    printf("[%s] = %p, ", String_Get(entry->key), entry->value);
            }
        }
    }
    
    printf("}\n");
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

size_t hash(const char *key, size_t t_size) {
    size_t key_size = String_ChrLen(key), hash = 0;
    for(int i = 0; i < key_size; i++)
        hash = hash * 37 + key[i];

    return (size_t) hash % t_size;
}

size_t nextprime(size_t num) {
    while(!isprime(num++));
    return --num;
}

boolean isprime(size_t num) {
    if(num > 2 && num % 2 == 0)
        return FALSE;

    for(int i = 3; i < sqrt(num); i++)
        if(num % i == 0)
            return FALSE;

    return TRUE;
}



/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
