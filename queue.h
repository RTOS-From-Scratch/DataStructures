/*
 * Description : An implementation for -Queue (FIFO)-, based on LinkedList
 * Usage	   : 
 * Author	   : Baron Leonardo <mohamedayman.fcis@zoho.com>
 * License	   : Copyright (C) 2016 RTOS From Scratch
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


#ifndef QUEUE_H_
#define QUEUE_H_

#include "linkedlist.h"
#include <stdlib.h>
#include <stdbool.h>

// A type represent `Node` in queue
typedef struct LinkedList_Node Queue_Node;
// A type represent `Queue`
typedef struct LinkedList_List Queue;

// create a new linked list
Queue* Queue_new();

// [ , , , , , , ] <- push
// if the size is `ZERO` -> the data is a pointer
void Queue_push( Queue* queue, void* data, size_t size );
// check if the queue is empty
bool Queue_isEmpty(Queue *list);
// [ , , , , , , ] -> pop
void* Queue_pop( Queue* queue );
// get the current length of the queue
size_t Queue_getLength( Queue *queue );
// get data of the head node
void* Queue_getHeadData(Queue *queue);
// clean: acts like a destructor
// if the data in the nodes are in the heap -> heap_data is `True`
void Queue_clean(Queue *queue, bool is_heap);

#endif // !QUEUE_H_
