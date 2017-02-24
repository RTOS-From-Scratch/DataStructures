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


#include "stack.h"

// create a new linked list
Stack* Stack_new()
{
    return LinkedList_new();
}

// [ , , , , , , ] <- push
// if the size is `ZERO` -> the data is a pointer
void Stack_push( Stack* stack, void* data, size_t size )
{
    LinkedList_pushBack( stack, data, size );
}

// check if the stack is empty
bool Stack_isEmpty(Stack *stack)
{
    return LinkedList_isEmpty(stack);
}

// [ , , , , , , ] -> pop
void* Stack_pop( Stack* stack )
{
    return LinkedList_getData( LinkedList_popBack(stack) );
}

// get the current length of the stack
size_t Stack_getLength( Stack *stack )
{
    return LinkedList_getLength(stack);
}

void* Stack_getTailData(Stack *stack)
{
	return LinkedList_getTailData(stack);
}

// clean: acts like a destructor
// if the data in the nodes are in the heap -> heap_data is `True`
void Stack_clean(Stack *stack, bool is_heap)
{
    LinkedList_clean( stack, is_heap );
}
