#include "sorted_linkedlist_with_id.h"
#include <stdlib.h>
#include <string.h>

void SortedLinkedListWithID_new( byte len,
                                 byte id,
                                 SortedLinkedListWithID_t* s_linkedList )
{
    SortedLinkedListWithID_init(NULL, len, id, s_linkedList);
}

void SortedLinkedListWithID_init( SortedLinkedListWithID_Node_t nodes[],
                                  byte len,
                                  byte id,
                                  SortedLinkedListWithID_t* s_linkedList )
{
//    SortedLinkedList_init( (SortedLinkedList_Node_t *)nodes, len, s_linkedList );
    if( s_linkedList is NULL )
        return;

    if(nodes is NULL)
    {
        s_linkedList->nodes = malloc( len * sizeof(SortedLinkedListWithID_Node_t) );
        s_linkedList->needToBeFreed = true;
    }

    else
    {
        s_linkedList->nodes = nodes;
        s_linkedList->needToBeFreed = false;
    }

    s_linkedList->head = -1;
    s_linkedList->tail = -1;
    s_linkedList->length = len;
    s_linkedList->id = id;
}

bool SortedLinkedListWithID_insert( SortedLinkedListWithID_t* s_linkedList, void* data, byte index )
{
    byte tail_node_index = s_linkedList->length - 1;

    if( index > tail_node_index )
        return false;

    if( data is NULL )
        return false;

    if( s_linkedList->nodes[index].data is_not NULL )
        return false;

    if( s_linkedList->head EQUAL -1)
    {
        s_linkedList->nodes[index].prev = index;
        s_linkedList->nodes[index].next = index;

        s_linkedList->tail = index;
        s_linkedList->head = index;
    }

    else if( index < s_linkedList->head )
    {
        s_linkedList->nodes[index].next = s_linkedList->head;
        s_linkedList->nodes[index].prev = index;
        s_linkedList->nodes[s_linkedList->head].prev = index;

        s_linkedList->head = index;

    }

    else if( index > s_linkedList->tail )
    {
        s_linkedList->nodes[index].prev = s_linkedList->tail;
        s_linkedList->nodes[index].next = index;
        s_linkedList->nodes[s_linkedList->tail].next = index;
        
        s_linkedList->tail = index;
    }

    else
    {
        byte nearest_filled_node_index;

        for(byte iii = index - 1, jjj = index + 1;
            iii >= s_linkedList->head && jjj <= s_linkedList->tail;
            iii--, jjj++)
        {
            if( s_linkedList->nodes[iii].data is_not NULL )
            {
                if( s_linkedList->nodes[iii].id EQUAL s_linkedList->id )
                {
                    nearest_filled_node_index = iii;
                    break;
                }
            }

            else if( s_linkedList->nodes[jjj].data is_not NULL )
            {
                if( s_linkedList->nodes[jjj].id EQUAL s_linkedList->id )
                {
                    nearest_filled_node_index = jjj;
                    break;
                }
            }
        }

        if( nearest_filled_node_index > index )
        {
            byte prev = s_linkedList->nodes[nearest_filled_node_index].prev;

            s_linkedList->nodes[nearest_filled_node_index].prev = index;
            s_linkedList->nodes[index].next = nearest_filled_node_index;

            s_linkedList->nodes[index].prev = prev;
            s_linkedList->nodes[prev].next = index;
        }

        else
        {
            byte next = s_linkedList->nodes[nearest_filled_node_index].next;

            s_linkedList->nodes[nearest_filled_node_index].next = index;
            s_linkedList->nodes[index].prev = nearest_filled_node_index;

            s_linkedList->nodes[index].next = next;
            s_linkedList->nodes[next].prev = index;
        }
    }

    s_linkedList->nodes[index].data = data;
    s_linkedList->nodes[index].id = s_linkedList->id;

    return true;
}

void* SortedLinkedListWithID_popHead( SortedLinkedListWithID_t* s_linkedList )
{
    int16_t head_index = s_linkedList->head;
    SortedLinkedListWithID_Node_t *head_node = &s_linkedList->nodes[head_index];
    void* data = head_node->data;

    if( head_index EQUAL -1 )
        return NULL;

    else if( head_index is_not s_linkedList->tail )
    {
        s_linkedList->nodes[head_node->next].prev = head_node->next;
        s_linkedList->head = head_node->next;
    }

    else
    {
        s_linkedList->head = -1;
        s_linkedList->tail = -1;
    }

    head_node->data = NULL;
    head_node->next = 0;
    head_node->prev = 0;

    return data;
}

void* SortedLinkedListWithID_popTail( SortedLinkedListWithID_t* s_linkedList )
{
    int16_t tail_index = s_linkedList->tail;
    SortedLinkedListWithID_Node_t *tail_node = &s_linkedList->nodes[tail_index];
    void* data = tail_node->data;

    if( tail_index EQUAL -1 )
        return NULL;

    else if( tail_index is_not s_linkedList->head )
    {
        s_linkedList->nodes[tail_node->prev].next = tail_node->prev;
        s_linkedList->tail = tail_node->prev;
    }

    else
    {
        s_linkedList->head = -1;
        s_linkedList->tail = -1;
    }

    tail_node->data = NULL;
    tail_node->next = 0;
    tail_node->prev = 0;
    tail_node->id   = 0;

    return data;
}

void* SortedLinkedListWithID_popAt( SortedLinkedListWithID_t* s_linkedList, byte index )
{
    if( index > (s_linkedList->length - 1) )
        return NULL;

    if( s_linkedList->nodes[index].data is NULL )
        return NULL;

    if( s_linkedList->id NOT_EQUAL s_linkedList->nodes[index].id )
        return NULL;

    if( index EQUAL s_linkedList->head )
        return SortedLinkedListWithID_popHead(s_linkedList);

    else if( index EQUAL s_linkedList->tail )
        return SortedLinkedListWithID_popTail(s_linkedList);

    else
    {
        byte prev = s_linkedList->nodes[index].prev;
        byte next = s_linkedList->nodes[index].next;
        void* data = s_linkedList->nodes[index].data;

        s_linkedList->nodes[prev].next = next;
        s_linkedList->nodes[next].prev = prev;

        s_linkedList->nodes[index].next = 0;
        s_linkedList->nodes[index].prev = 0;
        s_linkedList->nodes[index].id   = 0;
        s_linkedList->nodes[index].data = NULL;

        return data;
    }
}

void* SortedLinkedListWithID_getHeadData( SortedLinkedListWithID_t* s_linkedList )
{
    return SortedLinkedListWithID_getData(s_linkedList, s_linkedList->head);
}

void* SortedLinkedListWithID_getTailData( SortedLinkedListWithID_t* s_linkedList )
{
    return SortedLinkedListWithID_getData(s_linkedList, s_linkedList->tail);
}

void* SortedLinkedListWithID_getData( SortedLinkedListWithID_t* s_linkedList, byte index )
{
    if( index > (s_linkedList->length - 1) )
        return NULL;

    return s_linkedList->nodes[index].data;
}

bool SortedLinkedListWithID_updateData( SortedLinkedListWithID_t* s_linkedList, byte index, void* newData )
{
    if( index > (s_linkedList->length - 1) )
        return false;

    s_linkedList->nodes[index].data = newData;

    return true;
}

bool SortedLinkedListWithID_isEmpty( SortedLinkedListWithID_t* s_linkedList )
{
    return s_linkedList->head EQUAL -1 ? true : false;
}

byte SortedLinkedListWithID_length( SortedLinkedListWithID_t* s_linkedList )
{
    return s_linkedList->length;
}

void SortedLinkedListWithID_clean( SortedLinkedListWithID_t* s_linkedList )
{
    if( s_linkedList->needToBeFreed )
        free(s_linkedList->nodes);

    else
        memset( s_linkedList->nodes, 0, (s_linkedList->length * sizeof(SortedLinkedListWithID_Node_t)) );

    s_linkedList->head = -1;
    s_linkedList->tail = -1;
    s_linkedList->id   = -1;
}
