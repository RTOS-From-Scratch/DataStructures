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

void SortedLinkedList_new( byte len, SortedLinkedList_t* queue );
// this function is used if the nodes array is already created
// and you want to use this library for queue management only
void SortedLinkedList_init( SortedLinkedList_Node_t nodes[], byte len, SortedLinkedList_t* queue );
bool SortedLinkedList_insert( SortedLinkedList_t* queue, void* data, byte index );
void* SortedLinkedList_popHead( SortedLinkedList_t* queue );
void* SortedLinkedList_popTail( SortedLinkedList_t* queue );
void* SortedLinkedList_popAt( SortedLinkedList_t* queue, byte index );
void* SortedLinkedList_getHeadData( SortedLinkedList_t* queue );
void* SortedLinkedList_getTailData( SortedLinkedList_t* queue );
void* SortedLinkedList_getData( SortedLinkedList_t* queue, byte index );
bool SortedLinkedList_updateData( SortedLinkedList_t* queue, byte index, void* newData );
bool SortedLinkedList_isEmpty( SortedLinkedList_t* queue );
byte SortedLinkedList_length( SortedLinkedList_t* queue );
void SortedLinkedList_clean( SortedLinkedList_t* queue );

#endif //SORTED_LINKEDLIST_H_
