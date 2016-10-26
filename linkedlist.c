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

void* LinkedList_push_back( LinkedList_list* list, void* data, size_t size )
{
	LinkedList_Node* node;

	if( size != 0 )
	{
		node = malloc(sizeof(LinkedList_Node) + size);
		memcpy(node->data, data, size);
	}
	
	else
	{
		node = malloc(sizeof(LinkedList_Node) + sizeof(void*));
		memcpy(node->data, &data, sizeof(void*));
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
void* LinkedList_push_front( LinkedList_list* list, void* data, size_t size )
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

void LinkedList_clean(LinkedList_list *list, bool heap_data)
{
	LinkedList_Node *current_node = list->head;
	LinkedList_Node *next_node = list->head;

	while((current_node = next_node) != NULL)
	{
		next_node = next_node->next;

		if( heap_data == true )
		{
			// get the saved address from the array of bytes
			free( (void*)*(uintptr_t*)(current_node->data) );
		}

		free(current_node);
	}

	list->length = 0;
	list->head = NULL;
	list->tail = NULL;

	free(list);
}