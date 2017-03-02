/*
 * Description : An implementation for -Stack (LIFO)-, based on LinkedList
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

// A type represent `Node` in stack
typedef struct LinkedList_Node Stack_Node;
// A type represent `Stack`
typedef struct LinkedList_List Stack;

// create a new Stack
Stack* Stack_new();

// [ , , , , , , ] <- push
// if the size is `ZERO` -> the data is a pointer
void Stack_push( Stack* stack, void* data, size_t size );
// check if the stack is empty
bool Stack_isEmpty(Stack *stack);
// [ , , , , , , ] -> pop
void* Stack_pop( Stack* stack );
// get the current length of the stack
size_t Stack_getLength( Stack *stack );
// get data of the tail node
void* Stack_getTailData(Stack *stack);
// clean: acts like a destructor
// if the data in the nodes are in the heap -> heap_data is `True`
void Stack_clean(Stack *stack, bool is_heap);

#endif // !QUEUE_H_
