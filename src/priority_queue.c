/*
 * Description : A special type of FIFO (first-in first-out).
 * Usage       : This queue is used if the data has priority
 *               and the we need to get the higher one always.
 * Author      : Baron Leonardo <mohamedayman.fcis@zoho.com>
 * License     : Copyright (C) 2016 RTOS From Scratch
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "priority_queue.h"
#include "../../Drivers/src/UART.h"
#include "../../helper_libraries/src/itoa.h"

typedef struct PQueue_Node {
    int8_t priority;
    void* data;
} PQueue_Node;

struct PQueue {
    size_t length;
    long curr_index;
    PQueue_Node queue[];
};

static void __swim_LastElement( PQueue *queue );
static void __sink_LastElement( PQueue *queue );
static void __exchange_node(PQueue_Node * node1, PQueue_Node * node2 );

PQueue *PQueue_new( size_t queue_length )
{
    PQueue *p_queue = malloc( sizeof(PQueue) +
                              queue_length * sizeof(PQueue_Node) );

    // default values
    p_queue->length = queue_length;
    p_queue->curr_index = -1;

    return p_queue;
}

long PQueue_push(PQueue *queue, int8_t priority, void *data)
{
    // TODO: check length first
    if(! queue) return -1;

    queue->queue[++queue->curr_index].priority = priority;
    queue->queue[queue->curr_index].data = data;

    __swim_LastElement( queue );

    return queue->length;
}

bool PQueue_isEmpty(PQueue *p_queue)
{
    if(p_queue->length == -1) return true;
    else return false;
}

void *PQueue_popHead(PQueue *p_queue)
{
    void* head_data = p_queue->queue[0].data;
//    __exchange_node(&p_queue->queue[0], &p_queue->queue[p_queue->curr_index]);
    p_queue->queue[0] = p_queue->queue[p_queue->curr_index];
    p_queue->curr_index--;
    __sink_LastElement(p_queue);

    return head_data;
}

size_t PQueue_getLength(PQueue *p_queue)
{
    return p_queue->curr_index;
}

void *PQueue_getHeadData(PQueue *p_queue)
{
    return p_queue->queue[0].data;
}

int8_t PQueue_getHeadPriority(PQueue *p_queue)
{
    return p_queue->queue[0].priority;
}

void PQueue_clean(PQueue *p_queue)
{
    free(p_queue);
}

void __sink_LastElement( PQueue *queue )
{
    PQueue_Node* node = queue->queue;
    int current_parent = 0;
    int current_child  = 1;

//    char buffer[3];
//    UART_writeLine(U0_Tx, itoa(queue->curr_index, buffer, 10));

    while(current_child < queue->curr_index)
    {
        // check if the right child exists
        // check if the right child has higher priority
        if(current_child + 1 <= queue->curr_index &&
           node[current_child].priority < node[current_child + 1].priority)
            current_child++;

        __exchange_node(&node[current_parent], &node[current_child]);

        current_parent = current_child;
        current_child  = current_parent * 2 + 1;
    }
}

void __exchange_node(PQueue_Node * node1, PQueue_Node * node2 )
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

void __swim_LastElement( PQueue *pqueue )
{
    // 1- child -> last node
    // 2- cmp child, parent where parent -> (child-1)/2
    // 3- child > parent -> swap and child_index = parent_index
    // 4- else get out
    int8_t current_index = pqueue->curr_index;
    int8_t parent_index;
    PQueue_Node* queue = pqueue->queue;

    while (current_index > 0 &&
           queue[parent_index =  (current_index - 1) / 2].priority < queue[current_index].priority)
    {
        __exchange_node(&queue[parent_index], &queue[current_index]);
        current_index = parent_index;
    }
}

 void PQueue_print(PQueue *p_queue)
 {
     char buffer[3];

     for(int iii = 0; iii <= p_queue->curr_index; ++iii)
     {
         UART_writeLine(U0_Tx, (char*)itoa(p_queue->queue[iii].priority, buffer, 10));
         UART_write(U0_Tx, '\n');
     }
 }
