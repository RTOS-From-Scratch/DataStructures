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

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "inner/__priority_queue.h"

// A type represent `PQueue`
typedef __PQueue PQueue;

// create a new Priority Queue
PQueue* PQueue_new(size_t queue_length);

// [ , , , , , , ] <- push
// if the size is `ZERO` -> the data is a pointer
long PQueue_push(PQueue* queue, int8_t priority, void* data);

// check if the priority queue is empty
bool PQueue_isEmpty(PQueue *p_queue);

// pop <- [ , , , , , , ]
void* PQueue_popHead( PQueue *p_queue );

// get the current length of the priority queue
size_t PQueue_getLength( PQueue *p_queue );

// get data of the head node
void* PQueue_getHeadData(PQueue *p_queue);

// get the priority of the head node
int8_t PQueue_getHeadPriority(PQueue *p_queue);

// remove node from PQueue
bool PQueue_remove(PQueue *p_queue, PQueue_nodeIndex index);

// clean: acts like a destructor
void PQueue_clean(PQueue *p_queue);

#endif // PRIORITY_QUEUE_H_
