//
//  StringList.h
//  lec2
//
//  Created by Francisco on 6/28/15.
//  Updated: 07/03/16
//  Copyright (c) 2015 Francisco. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>
#include <stdlib.h>
#include "globalconst.h"

typedef struct
{
    size_t reserved;
    size_t size;
    void ** arr;
} ArrayList;

typedef ArrayList* ArrayListPtr;

static const int INITIAL_SIZE_STRING_LIST = 100;

boolean ArrayList_New(ArrayList * list);
boolean ArrayList_Expand(ArrayList * list);
boolean ArrayList_Add(ArrayList * list, void * item);

void * ArrayList_GetList(ArrayList * list);
inline size_t ArrayList_GetSize(ArrayList * list);

//also need to define

void ArrayList_Free(ArrayList * list); 
boolean ArrayList_Remove(ArrayList * list, size_t index);
boolean ArrayList_RemoveLast(ArrayList *list); //remove last item and updates
boolean ArrayList_Set(ArrayList *list, size_t index, void * item); //it will expand if needed  D
void * ArrayList_Get(ArrayList *list, size_t index);
boolean ArrayList_Clear(ArrayList * list); //must do compact
boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source);
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved);
boolean ArrayList_Compact(ArrayList * list); //it compacts to size + 100 if possible.
void ArrayList_Print(ArrayList *list);

//optional
///boolean ArrayList_InitStruct(ArrayList ** list);
///boolean ArrayList_FreeStruct(ArrayList ** list);

#endif /* defined(ArrayList_h) */
