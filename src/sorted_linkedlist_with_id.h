#ifndef SORTED_LINKEDLIST_WITH_ID_H_
#define SORTED_LINKEDLIST_WITH_ID_H_

#include <stdbool.h>
#include <stdint.h>
#include "Misc/src/definitions.h"
#include "sorted_linkedlist.h"

typedef struct SortedLinkedListWithID_Node_t {
    void* data;
    byte prev;
    byte next;
    byte id;
} SortedLinkedListWithID_Node_t;

typedef struct SortedLinkedListWithID_t {
    SortedLinkedListWithID_Node_t* nodes;
    byte length;
    int16_t head;
    int16_t tail;
    bool needToBeFreed;
    int16_t id;
} SortedLinkedListWithID_t;

void SortedLinkedListWithID_new( byte len,
                                 byte id,
                                 SortedLinkedListWithID_t* s_linkedList );
// this function is used if the nodes array is already created
// and you want to use this library for s_linkedList management only
void SortedLinkedListWithID_init( SortedLinkedListWithID_Node_t nodes[],
                                  byte len,
                                  byte id,
                                  SortedLinkedListWithID_t* s_linkedList );
bool SortedLinkedListWithID_insert( SortedLinkedListWithID_t* s_linkedList,
                                    void* data,
                                    byte index );
void* SortedLinkedListWithID_popHead( SortedLinkedListWithID_t* s_linkedList );
void* SortedLinkedListWithID_popTail( SortedLinkedListWithID_t* s_linkedList );
void* SortedLinkedListWithID_popAt( SortedLinkedListWithID_t* s_linkedList,
                                    byte index );
void* SortedLinkedListWithID_getHeadData( SortedLinkedListWithID_t* s_linkedList );
void* SortedLinkedListWithID_getTailData( SortedLinkedListWithID_t* s_linkedList );
void* SortedLinkedListWithID_getData( SortedLinkedListWithID_t* s_linkedList,
                                      byte index );
bool SortedLinkedListWithID_updateData( SortedLinkedListWithID_t* s_linkedList,
                                        byte index,
                                        void* newData );
bool SortedLinkedListWithID_isEmpty( SortedLinkedListWithID_t* s_linkedList );
byte SortedLinkedListWithID_length( SortedLinkedListWithID_t* s_linkedList );
void SortedLinkedListWithID_clean( SortedLinkedListWithID_t* s_linkedList );

#endif //SORTED_LINKEDLIST_WITH_ID_H_
