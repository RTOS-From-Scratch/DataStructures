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

#ifndef INVERTED_PRIORITY_QUEUE_H_
#define INVERTED_PRIORITY_QUEUE_H_

#include "priority_queue.h"
#include <stddef.h>
#include <stdint.h>

// A type represent `IPQueue`
typedef __PQueue IPQueue;

// create a new Inverted Priority Queue
IPQueue* IPQueue_new( uint16_t length );

// [ , , , , , , ] <- push
uint16_t IPQueue_push( IPQueue* inv_p_queue, int8_t priority, void* data );

// check if the inverted priority queue is empty
bool IPQueue_isEmpty( IPQueue *inv_p_queue );

// pop <- [ , , , , , , ]
void* IPQueue_popHead( IPQueue *inv_p_queue );

// get the current length of the inverted priority queue
size_t IPQueue_getLength( IPQueue *inv_p_queue );

// get data of the head node
void* IPQueue_getHeadData( IPQueue *inv_p_queue );

// get the priority of the head node
int8_t IPQueue_getHeadPriority( IPQueue *inv_p_queue );

// remove node from PQueue
bool IPQueue_remove( IPQueue *inv_p_queue, void* data );

// clean: acts like a destructor
void IPQueue_clean( IPQueue *inv_p_queue );

#endif // INVERTED_PRIORITY_QUEUE_H_
