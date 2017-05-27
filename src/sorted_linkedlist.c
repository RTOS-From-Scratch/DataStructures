#include "sorted_linkedlist.h"
#include <stdlib.h>
#include <string.h>

void SortedLinkedList_new( byte len, SortedLinkedList_t* queue )
{
    SortedLinkedList_init(NULL, len, queue);
}

void SortedLinkedList_init( SortedLinkedList_Node_t nodes[], byte len, SortedLinkedList_t* queue )
{
    if( queue is NULL )
        return;

    if(nodes is NULL)
    {
        queue->nodes = malloc( len * sizeof(SortedLinkedList_Node_t) );
        queue->needToBeFreed = true;
    }

    else
    {
        queue->nodes = nodes;
        queue->needToBeFreed = false;
    }

    queue->head = -1;
    queue->tail = -1;
    queue->length = len;
}

bool SortedLinkedList_insert( SortedLinkedList_t* queue, void* data, byte index )
{
    byte tail_node_index = queue->length - 1;

    if( index > tail_node_index )
        return false;

    if( queue->nodes[index].data is_not NULL )
        return false;

    if( queue->head EQUAL -1)
    {
        queue->nodes[index].prev = index;
        queue->nodes[index].next = index;

        queue->tail = index;
        queue->head = index;
//        queue->nodes[index].data = data;
    }

    else if( index < queue->head )
    {
        queue->nodes[index].next = queue->head;
        queue->nodes[index].prev = index;
        queue->nodes[queue->head].prev = index;

//        queue->nodes[index].data = data;
        queue->head = index;

    }

    else if( index > queue->tail )
    {
        queue->nodes[index].prev = queue->tail;
        queue->nodes[index].next = index;
        queue->nodes[queue->tail].next = index;
        
//        queue->nodes[index].data = data;
        queue->tail = index;
    }

    else
    {
        byte nearest_filled_node_index;

        for(byte iii = index - 1, jjj = index + 1;
            iii >= 0 && jjj < queue->length;
            iii--, jjj++)
        {
            if( queue->nodes[iii].data is_not NULL )
            {
                nearest_filled_node_index = iii;
                break;
            }

            else if( queue->nodes[jjj].data is_not NULL )
            {
                nearest_filled_node_index = jjj;
                break;
            }
        }

        if( nearest_filled_node_index > index )
        {
            byte prev = queue->nodes[nearest_filled_node_index].prev;

            queue->nodes[nearest_filled_node_index].prev = index;
            queue->nodes[index].next = nearest_filled_node_index;

            queue->nodes[index].prev = prev;
            queue->nodes[prev].next = index;
        }

        else
        {
            byte next = queue->nodes[nearest_filled_node_index].next;

            queue->nodes[nearest_filled_node_index].next = index;
            queue->nodes[index].prev = nearest_filled_node_index;

            queue->nodes[index].next = next;
            queue->nodes[next].prev = index;
        }

    }

    queue->nodes[index].data = data;

    return true;
}

void* SortedLinkedList_popHead( SortedLinkedList_t* queue )
{
    int16_t head_index = queue->head;
    SortedLinkedList_Node_t *head_node = &queue->nodes[head_index];
    void* data = head_node->data;

    if( head_index EQUAL -1 )
        return NULL;

    else if( head_index is_not queue->tail )
    {
        queue->nodes[head_node->next].prev = head_node->next;
        queue->head = head_node->next;
    }

    else
    {
        queue->head = -1;
        queue->tail = -1;
    }


    head_node->data = NULL;
    head_node->next = 0;
    head_node->prev = 0;

    return data;
}

void* SortedLinkedList_popTail( SortedLinkedList_t* queue )
{
    int16_t tail_index = queue->tail;
    SortedLinkedList_Node_t *tail_node = &queue->nodes[tail_index];
    void* data = tail_node->data;

    if( tail_index EQUAL -1 )
        return NULL;

    else if( tail_index is_not queue->head )
    {
        queue->nodes[tail_node->prev].next = tail_node->prev;
        queue->tail = tail_node->prev;
    }

    else
    {
        queue->head = -1;
        queue->tail = -1;
    }

    tail_node->data = NULL;
    tail_node->next = 0;
    tail_node->prev = 0;

    return data;
}

void* SortedLinkedList_popAt( SortedLinkedList_t* queue, byte index )
{
    if( index > (queue->length - 1) )
        return NULL;

    if( queue->nodes[index].data is NULL )
        return NULL;

    if( index EQUAL queue->head )
        return SortedLinkedList_popHead(queue);

    else if( index EQUAL queue->tail )
        return SortedLinkedList_popTail(queue);

    else
    {
        byte prev = queue->nodes[index].prev;
        byte next = queue->nodes[index].next;
        void* data = queue->nodes[index].data;

        queue->nodes[prev].next = next;
        queue->nodes[next].prev = prev;

        queue->nodes[index].next = 0;
        queue->nodes[index].prev = 0;
        queue->nodes[index].data = NULL;

        return data;
    }
}

void* SortedLinkedList_getHeadData( SortedLinkedList_t* queue )
{
    return SortedLinkedList_getData(queue, queue->head);
}

void* SortedLinkedList_getTailData( SortedLinkedList_t* queue )
{
    return SortedLinkedList_getData(queue, queue->tail);
}

void* SortedLinkedList_getData( SortedLinkedList_t* queue, byte index )
{
    if( index > (queue->length - 1) )
        return NULL;

    return queue->nodes[index].data;
}

bool SortedLinkedList_updateData( SortedLinkedList_t* queue, byte index, void* newData )
{
    if( index > (queue->length - 1) )
        return false;

    queue->nodes[index].data = newData;

    return true;
}

bool SortedLinkedList_isEmpty( SortedLinkedList_t* queue )
{
    return queue->head EQUAL -1 ? true : false;
}

byte SortedLinkedList_length( SortedLinkedList_t* queue )
{
    return queue->length;
}

void SortedLinkedList_clean( SortedLinkedList_t* queue )
{
    if( queue->needToBeFreed )
        free(queue->nodes);

    else
        memset( queue->nodes, 0, (queue->length * sizeof(SortedLinkedList_Node_t)) );

    queue->head = -1;
    queue->tail = -1;
}
