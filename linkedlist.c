/* Author	   : Baron Leonardo <mohamedayman.fcis@zoho.com>
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

#include "linkedlist.h"
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;

struct LinkedList_Node {
	LinkedList_Node* next;
	LinkedList_Node* prev;
	byte data[];
};

struct LinkedList_list {
	uint32_t length;
	LinkedList_Node *head;      /* List head, dummy node. */
    LinkedList_Node *tail;      /* List tail, dummy node. */
};

LinkedList_list* LinkedList_new()
{
	LinkedList_list* list = malloc( sizeof(LinkedList_list) );
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;

	return list;
}

// #include <stdio.h>

void* LinkedList_push_back( LinkedList_list* list, void* data, size_t size, bool data_local )
{
	LinkedList_Node* node = malloc(sizeof(LinkedList_Node) + size);
	// printf("%lu\n", sizeof(LinkedList_Node) + size);
	// printf("%lu\n", sizeof(2 * sizeof(LinkedList_list *)) + size);
	// printf("%p %p %p %p\n", &node->next, &node->prev, ((void*)node + 2 * sizeof(void*)), &node->data);

	if( node == NULL )
		return NULL;

	if( data_local == true )
	{
		// this point to the address should be used for node's data 
		// node->data = node->prev + sizeof(void*);
		// node->data = malloc(size);
		memcpy(node->data, data, size);
	}

	else
	{
		void* ptr = node->data;
		ptr = data;
	}

	if( list->length != 0 )
	{
		list->tail->next = node;
		node->prev = list->tail;
	}

	else
	{
		list->head = node;
		node->prev = NULL;
	}

	list->tail = node;
	node->next = NULL;
	list->length++;

	return node;
}

// TODO:
void* LinkedList_push_front( LinkedList_list* list, void* data, size_t size, bool is_data_local )
{

}

// TODO:
void* LinkedList_pop_back( LinkedList_list* list )
{

}

// TODO:
void* LinkedList_pop_front( LinkedList_list* list )
{

}

void* LinkedList_get_data(LinkedList_Node *node)
{
	return node->data;
}

void* LinkedList_get_begin(LinkedList_list* list)
{
	return list->head;
}

void* LinkedList_get_last(LinkedList_list* list)
{
	return list->tail;
}

size_t LinkedList_get_length( LinkedList_list *list )
{
	return list->length;
}

void* LinkedList_prev(LinkedList_Node* node)
{
	return node->prev;
}

void* LinkedList_next(LinkedList_Node* node)
{
	return node->next;
}

// TODO:
bool LinkedList_remove(LinkedList_Node* node)
{
	return true;
}

// TODO
bool LinkedList_remove_from(LinkedList_Node* from, LinkedList_Node* to)
{
	return true;
}

void LinkedList_clean(LinkedList_list *list)
{
	LinkedList_Node *current_node = list->head;
	LinkedList_Node *next_node = list->head;
	bool data_is_inside_node = ( (void*)current_node->data == ((void*)current_node + 2 * sizeof(void*)) ); 

	while((current_node = next_node) != NULL)
	{
		next_node = next_node->next;
		if( data_is_inside_node == false )
			free(current_node->data);
		free(current_node);
	}

	list->length = 0;
	list->head = NULL;
	list->tail = NULL;

	free(list);
}