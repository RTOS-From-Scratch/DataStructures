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


#include "queue.h"

// create a new linked list
Queue* Queue_new()
{
    return LinkedList_new();
}

// if the size is `ZERO` -> the data is a pointer
void Queue_push( Queue* queue, void* data, size_t size )
{
    LinkedList_pushFront( queue, data, size );
}

bool Queue_isEmpty(Queue *queue)
{
    return LinkedList_isEmpty(queue);
}

void* Queue_pop( Queue* queue )
{
    return LinkedList_getData( LinkedList_popFront(queue) );
}

size_t Queue_getLength( Queue *queue )
{
    return LinkedList_getLength(queue);
}

void* Queue_getHeadData(Queue *queue)
{
    return LinkedList_getHeadData(queue);
}

// clean: acts like a destructor
// if the data in the nodes are in the heap -> heap_data is `True`
void Queue_clean(Queue *queue, bool is_heap)
{
    LinkedList_clean( queue, is_heap );
}
