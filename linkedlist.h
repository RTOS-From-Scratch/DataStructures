/* Description : An implementation for LIFO -Linked List-, inspired by Linux kernel
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

typedef struct LinkedList_Node LinkedList_Node;
typedef struct LinkedList_list LinkedList_list;

LinkedList_list* LinkedList_new();

void* LinkedList_push_back( LinkedList_list* list, void* data, size_t size, bool is_data_local );
void* LinkedList_push_front( LinkedList_list* list, void* data, size_t size, bool is_data_local );
void* LinkedList_pop_back( LinkedList_list* list );
void* LinkedList_pop_front( LinkedList_list* list );
size_t LinkedList_get_length( LinkedList_list *list );
void* LinkedList_get_data(LinkedList_Node *node);
void* LinkedList_get_begin(LinkedList_list* list);
void* LinkedList_get_last(LinkedList_list* list);
void* LinkedList_next(LinkedList_Node* node);
void* LinkedList_prev(LinkedList_Node* node);
bool LinkedList_remove(LinkedList_Node* node);
bool LinkedList_remove_from(LinkedList_Node* from, LinkedList_Node* to);
void LinkedList_clean(LinkedList_list *list);

#endif /*LINKEDLIST_H_*/