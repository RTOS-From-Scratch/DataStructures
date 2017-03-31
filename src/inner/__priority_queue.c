#include "__priority_queue.h"
#include "Drivers/src/UART.h"
#include "Misc/src/itoa.h"

void __exchange_node(__PQueue_Node * node1, __PQueue_Node * node2 )
{
    // exchange data
    long tmp = (long)node1->data;
    node1->data = node2->data;
    node2->data = (void *)tmp;

    // exchange priority
    tmp = node1->priority;
    node1->priority = node2->priority;
    node2->priority = (int8_t)tmp;
}

void __sink_LastElement( __PQueue *p_queue )
{
    __PQueue_Node* queue = p_queue->queue;
    int current_parent = 0;
    int current_child  = current_parent * 2 + 1;

    while(current_child < p_queue->curr_index)
    {
        // check if the right child exists
        // check if the right child has higher priority
        if(current_child + 1 <= p_queue->curr_index &&
           queue[current_child].priority < queue[current_child + 1].priority)
            current_child++;

        __exchange_node(&queue[current_parent], &queue[current_child]);

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
        __exchange_node(&queue[parent_index], &queue[current_index]);
        current_index = parent_index;
    }
}

void __sink_LastElement_inverted( __PQueue *p_queue )
{
    __PQueue_Node* queue = p_queue->queue;
    int current_parent = 0;
    int current_child  = 1;

    while(current_child < p_queue->curr_index)
    {
        // check if the right child exists
        // check if the right child has higher priority
        if(current_child + 1 <= p_queue->curr_index &&
           queue[current_child].priority > queue[current_child + 1].priority)
            current_child++;

        __exchange_node(&queue[current_parent], &queue[current_child]);

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
        __exchange_node(&queue[parent_index], &queue[current_index]);
        current_index = parent_index;
    }
}
