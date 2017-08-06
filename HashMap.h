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


#include "globalconst.h"
#include "ArrayList.h"
#include "String.h"

#ifndef HashMap_h
#define HashMap_h

typedef struct {
    String *key;
    void *value;
} MapEntry;

typedef struct {
    size_t size;
    ArrayList *table;
} HashMap;

static const int INITIAL_NUM_BUCKETS = 153;         // Prime table size ensures good distribution of values

boolean HashMap_New(HashMap *map);
void HashMap_Free(HashMap *map);
size_t HashMap_GetSize(HashMap *map);
boolean HashMap_Set(HashMap *map, char *key, void *value);
void *HashMap_Get(HashMap *map, char *key);
void *HashMap_Remove(HashMap *map, char *key);
boolean HashMap_Clear(HashMap *map);
boolean HashMap_Expand(HashMap *map, size_t new_size);

boolean HashEntry_Free(MapEntry *entry);

void HashMap_Print(HashMap *map);

#endif


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
