#include "__priority_queue.h"
#include "Drivers/src/UART.h"
#include "Misc/src/itoa.h"
#include "Misc/src/definitions.h"

void __PQueue_Node_move(__PQueue_Node* src, __PQueue_Node* dest)
{
    dest->data = src->data;
    dest->priority = src->priority;
}

void __PQueue_Node_sink( __PQueue *p_queue, uint16_t index )
{
    __PQueue_Node* queue = p_queue->queue;
    int current_parent = index;
    int current_child  = current_parent * 2 + 1;

    while(current_child < p_queue->curr_index)
    {
        // check if the right child exists
        // check if the right child has higher priority
        if(current_child + 1 <= p_queue->curr_index &&
           queue[current_child].priority < queue[current_child + 1].priority)
            current_child++;

        SWAP(queue[current_parent], queue[current_child], __PQueue_Node);

        current_parent = current_child;
        current_child  = current_parent * 2 + 1;
    }
}

void __swim_LastElement( __PQueue *p_queue )
{
    // 1- child -> last node
    // 2- cmp child, parent where parent -> (child-1)/2
    // 3- child > parent -> swap and child_index = parent_index
    // 4- else get out
    int8_t current_index = p_queue->curr_index;
    int8_t parent_index;
    __PQueue_Node* queue = p_queue->queue;

    while (current_index > 0 &&
           queue[parent_index =  (current_index - 1) / 2].priority < queue[current_index].priority)
    {
        SWAP(queue[parent_index], queue[current_index], __PQueue_Node);
        current_index = parent_index;
    }
}

void __IPQueue_Node_sink( __PQueue *p_queue_inv, uint16_t index )
{
    __PQueue_Node* queue = p_queue_inv->queue;
    int current_parent = index;
    int current_child  = current_parent * 2 + 1;

    while(current_child <= p_queue_inv->curr_index)
    {
        // check if the right child exists
        // check if the right child has higher priority
        if(current_child + 1 <= p_queue_inv->curr_index &&
           queue[current_child].priority > queue[current_child + 1].priority)
            current_child++;

        SWAP(queue[current_parent], queue[current_child], __PQueue_Node);

        current_parent = current_child;
        current_child  = current_parent * 2 + 1;
    }
}

void __swim_LastElement_inverted( __PQueue *p_queue )
{
    // 1- child -> last node
    // 2- cmp child, parent where parent -> (child-1)/2
    // 3- child > parent -> swap and child_index = parent_index
    // 4- else get out
    int8_t current_index = p_queue->curr_index;
    int8_t parent_index;
    __PQueue_Node* queue = p_queue->queue;

    while (current_index > 0 &&
           queue[parent_index =  (current_index - 1) / 2].priority > queue[current_index].priority)
    {
        SWAP(queue[parent_index], queue[current_index], __PQueue_Node);
        current_index = parent_index;
    }
}

int16_t __PQueue_find(__PQueue *p_queue, void* data)
{
    // FIXME: this disaster need to bed= implemented in another way
    // FIXME: the complexity of finding in O(n)
    for(uint16_t counter = 0; counter <= p_queue->curr_index; ++counter)
        if(p_queue->queue[counter].data == data)
            return counter;

    return -1;
}
