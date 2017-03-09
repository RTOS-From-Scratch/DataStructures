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

PQueue *PQueue_new( size_t queue_length )
{
    PQueue *p_queue = malloc( sizeof(PQueue) +
                              queue_length * sizeof(__PQueue_Node) );

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

void PQueue_print(PQueue *p_queue)
{
    __PQueue_print(p_queue);
}
