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

#include "inverted_priority_queue.h"

IPQueue *IPQueue_new( size_t queue_length )
{
    return PQueue_new(queue_length);
}

long IPQueue_push(IPQueue *queue, int8_t priority, void *data)
{
    // TODO: check length first
    if(! queue) return -1;

    queue->queue[++queue->curr_index].priority = priority;
    queue->queue[queue->curr_index].data = data;

    __swim_LastElement_inverted( queue );

    return queue->curr_index + 1;
}

bool IPQueue_isEmpty(IPQueue *p_queue)
{
    return PQueue_isEmpty(p_queue);
}

void *IPQueue_popHead(IPQueue *p_queue)
{
    void* head_data = p_queue->queue[0].data;
 //    __exchange_node(&p_queue->queue[0], &p_queue->queue[p_queue->curr_index]);
     p_queue->queue[0] = p_queue->queue[p_queue->curr_index];
     p_queue->curr_index--;

     // sink start from the root node
     __IPQueue_Node_sink(p_queue, 0);

     return head_data;
}

size_t IPQueue_getLength(IPQueue *p_queue)
{
    return PQueue_getLength(p_queue);
}

void *IPQueue_getHeadData(IPQueue *p_queue)
{
    return PQueue_getHeadData(p_queue);
}

int8_t IPQueue_getHeadPriority(IPQueue *p_queue)
{
    return PQueue_getHeadPriority(p_queue);
}

bool IPQueue_remove(IPQueue *p_queue, IPQueue_nodeIndex index)
{
    __PQueue_Node* queue = p_queue->queue;

    if(index > p_queue->curr_index) return false;

    // move last node into the node needed to be removed
    __PQueue_Node_move(&queue[p_queue->curr_index], &queue[index]);
    p_queue->curr_index--;

    __IPQueue_Node_sink(p_queue, index);

    return true;
}

void IPQueue_clean(IPQueue *p_queue)
{
    PQueue_clean(p_queue);
}
