/* Description : An implementation for -Linked List-, inspired by Linux kernel
 * Usage	   : 
 * Author	   : Baron Leonardo <mohamedayman.fcis@zoho.com>
 * License	   : Copyright (C) 2016 RTOS From Scratch
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdbool.h>

// A type represent `Node` in linked list
typedef struct LinkedList_Node LinkedList_Node;
// A type represent `LinkedList`
typedef struct LinkedList_List LinkedList_List;

// create a new linked list
LinkedList_List* LinkedList_new();

// pushback -> [ , , , , , , ]
// if the size is `ZERO` -> the data is a pointer
void* LinkedList_pushBack( LinkedList_List* list, void* data, size_t size );
// [ , , , , , , ] <- pushfront
// if the size is `ZERO` -> the data is a pointer
void* LinkedList_pushFront( LinkedList_List* list, void* data, size_t size );
// check if the list is empty
bool LinkedList_isEmpty(LinkedList_List *list);
// popback <- [ , , , , , , ]
void* LinkedList_popBack( LinkedList_List* list );
// [ , , , , , , ] -> popfront
void* LinkedList_popFront( LinkedList_List* list );
// get the current length of the linked list
size_t LinkedList_getLength( LinkedList_List *list );
// get data of a specific node
void* LinkedList_getData(LinkedList_Node *node);
// get data of the head node
void* LinkedList_getHeadData(LinkedList_List *list);
// get data of the tail node
void* LinkedList_getTailData(LinkedList_List *list);
// get the first node of the linked list
void* LinkedList_getBegin(LinkedList_List* list);
// get the last node of the linked list
void* LinkedList_getLast(LinkedList_List* list);
// get the next node from a specific node
void* LinkedList_next(LinkedList_Node* node);
// get the previous node from a specific node
void* LinkedList_prev(LinkedList_Node* node);
// remove a node
// if the data in this specific node is in the heap -> heap_data is `True`
bool LinkedList_remove(LinkedList_List *list, LinkedList_Node* node, bool heap_data);
// remove N nodes
// if the data in these specific nodes are in the heap -> heap_data is `True`
bool LinkedList_removeFrom(LinkedList_List *list, LinkedList_Node* from, LinkedList_Node* to, bool heap_data);
// clean: acts like a destructor
// if the data in the nodes are in the heap -> heap_data is `True`
void LinkedList_clean(LinkedList_List *list, bool is_heap);

#endif /*LINKEDLIST_H_*/