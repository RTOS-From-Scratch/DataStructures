#ifndef SORTED_LINKEDLIST_H_
#define SORTED_LINKEDLIST_H_

#include <stdbool.h>
#include <stdint.h>
#include "Misc/src/definitions.h"

typedef struct SortedLinkedList_Node_t {
    void* data;
    byte prev;
    byte next;
} SortedLinkedList_Node_t;

typedef struct SortedLinkedList_t {
    SortedLinkedList_Node_t* nodes;
    byte length;
    int16_t head;
    int16_t tail;
    bool needToBeFreed;
} SortedLinkedList_t;

void SortedLinkedList_new( byte len, SortedLinkedList_t* s_linkedList );
// this function is used if the nodes array is already created
// and you want to use this library for s_linkedList management only
void SortedLinkedList_init( SortedLinkedList_Node_t nodes[], byte len, SortedLinkedList_t* s_linkedList );
bool SortedLinkedList_insert( SortedLinkedList_t* s_linkedList, void* data, byte index );
void* SortedLinkedList_popHead( SortedLinkedList_t* s_linkedList );
void* SortedLinkedList_popTail( SortedLinkedList_t* s_linkedList );
void* SortedLinkedList_popAt( SortedLinkedList_t* s_linkedList, byte index );
void* SortedLinkedList_getHeadData( SortedLinkedList_t* s_linkedList );
void* SortedLinkedList_getTailData( SortedLinkedList_t* s_linkedList );
void* SortedLinkedList_getData( SortedLinkedList_t* s_linkedList, byte index );
bool SortedLinkedList_updateData( SortedLinkedList_t* s_linkedList, byte index, void* newData );
bool SortedLinkedList_isEmpty( SortedLinkedList_t* s_linkedList );
byte SortedLinkedList_length( SortedLinkedList_t* s_linkedList );
void SortedLinkedList_clean( SortedLinkedList_t* s_linkedList );

#endif //SORTED_LINKEDLIST_H_
