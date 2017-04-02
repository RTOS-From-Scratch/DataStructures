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

IPQueue *IPQueue_new(uint16_t length)
{
    return PQueue_new(length);
}

uint16_t IPQueue_push(IPQueue *inv_p_queue, int8_t priority, void *data)
{
    // TODO: check length first
    if(! inv_p_queue) return -1;

    inv_p_queue->queue[++inv_p_queue->curr_index].priority = priority;
    inv_p_queue->queue[inv_p_queue->curr_index].data = data;

    __swim_LastElement_inverted( inv_p_queue );

    return inv_p_queue->curr_index + 1;
}

bool IPQueue_isEmpty(IPQueue *inv_p_queue)
{
    return PQueue_isEmpty(inv_p_queue);
}

void *IPQueue_popHead(IPQueue *inv_p_queue)
{
    void* head_data = inv_p_queue->queue[0].data;
     inv_p_queue->queue[0] = inv_p_queue->queue[inv_p_queue->curr_index];
     inv_p_queue->curr_index--;

     // sink start from the root node
     __IPQueue_Node_sink(inv_p_queue, 0);

     return head_data;
}

size_t IPQueue_getLength(IPQueue *inv_p_queue)
{
    return PQueue_getLength(inv_p_queue);
}

void *IPQueue_getHeadData(IPQueue *inv_p_queue)
{
    return PQueue_getHeadData(inv_p_queue);
}

int8_t IPQueue_getHeadPriority(IPQueue *inv_p_queue)
{
    return PQueue_getHeadPriority(inv_p_queue);
}

bool IPQueue_remove(IPQueue *inv_p_queue, void* data)
{
    __PQueue_Node* queue = inv_p_queue->queue;

    // find the index of the node needed to be removed
    int16_t indexToBeRemove = __PQueue_find(inv_p_queue, data);

    // override the node needed to be removed by the last node
    queue[indexToBeRemove] = queue[inv_p_queue->curr_index--];

    __IPQueue_Node_sink(inv_p_queue, indexToBeRemove);

    return true;
}

void IPQueue_clean(IPQueue *inv_p_queue)
{
    PQueue_clean(inv_p_queue);
}
