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


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "globalconst.h"

#ifndef LinkedList_h
#define LinkedList_h

typedef struct node *NodePtr;

typedef struct node {
    void *data;
    NodePtr prev;
    NodePtr next;
} ListNode;

typedef struct {
    ListNode *head;
} LinkedList;

boolean LinkedList_New(LinkedList *list);
void LinkedList_Free(LinkedList *list);
boolean LinkedList_isEmpty(LinkedList *list);
size_t LinkedList_GetSize(LinkedList *list);
boolean LinkedList_Contains(LinkedList *list, void *item);
void *LinkedList_ItemAtIndex(LinkedList *list, size_t index);
boolean LinkedList_InsertAfter(ListNode *node, void *item);
boolean LinkedList_InsertBefore(ListNode *node, void *item);
boolean LinkedList_InsertBeginning(LinkedList *list, void *item);
boolean LinkedList_InsertEnd(LinkedList *list, void *item);
void *LinkedList_Remove(LinkedList *list, void *item);
void *LinkedList_RemoveFirst(LinkedList *list);
void *LinkedList_RemoveLast(LinkedList *list);
//void LinkedList_Clear(LinkedList *list);
LinkedList *LinkedList_toList(void **items, size_t n);
void **LinkedList_toArray(LinkedList *list);
//boolean LinkedList_ForEach(LinkedList *list, boolean (*callback)(ListNode *node, void *item));

void ListNode_Print(ListNode *node);
void LinkedList_Print(LinkedList *list);


#endif

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
