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

struct LinkedList_List {
	size_t length;
	LinkedList_Node *head;      /* List head, dummy node. */
    LinkedList_Node *tail;      /* List tail, dummy node. */
};

static LinkedList_Node* LinkedList_construct_node(void* data, size_t size);

LinkedList_List* LinkedList_new()
{
	LinkedList_List* list = malloc( sizeof(LinkedList_List) );
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;

	return list;
}

LinkedList_Node* LinkedList_construct_node(void* data, size_t size)
{
	LinkedList_Node* node;

	if( size != 0 )
	{
		node = malloc(sizeof(LinkedList_Node) + size);

		if( node == NULL )
			return NULL;

		memcpy(node->data, data, size);
	}
	
	else
	{
		node = malloc(sizeof(LinkedList_Node) + sizeof(void*));

		if( node == NULL )
			return NULL;

		memcpy(node->data, &data, sizeof(void*));
	}

	return node;
}

void* LinkedList_push_back( LinkedList_List* list, void* data, size_t size )
{
	LinkedList_Node* node = LinkedList_construct_node(data, size);

	if( node == NULL )
		return NULL;

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

void* LinkedList_push_front( LinkedList_List* list, void* data, size_t size )
{
	LinkedList_Node* node = LinkedList_construct_node(data, size);

	if( node == NULL )
		return NULL;

	if( list->length != 0 )
	{
		list->head->prev = node;
		node->next = list->head;
	}

	else
	{
		list->tail = node;
		node->prev = NULL;
	}

	list->head = node;
	node->prev = NULL;
	list->length++;

	return node;
}

void* LinkedList_pop_back( LinkedList_List* list )
{
	LinkedList_Node* node = list->tail;

	list->tail = list->tail->prev;
	list->tail->next = NULL;

	return node;
}

void* LinkedList_pop_front( LinkedList_List* list )
{
	LinkedList_Node* node = list->head;

	list->head = list->head->next;
	list->head->prev = NULL;

	return node;
}

void* LinkedList_get_data(LinkedList_Node *node)
{
	return node->data;
}

void* LinkedList_get_begin(LinkedList_List* list)
{
	return list->head;
}

void* LinkedList_get_last(LinkedList_List* list)
{
	return list->tail;
}

size_t LinkedList_get_length( LinkedList_List *list )
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

bool LinkedList_remove(LinkedList_List *list, LinkedList_Node* node, bool heap_data)
{
	if( list->length == 1 )
	{
		list->head = NULL;
		list->tail = NULL;
	}

	else if( node == list->head )
	{
		list->head = list->head->next;
		list->head->prev = NULL;
	}

	else if( node == list->tail )
	{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}

	else if( node == NULL )
	{
		return false;
	}

	else
	{
		LinkedList_Node *temp = node->prev;

		temp->next = node->next;
		node->next = temp;
	}

	// free the node and its data
	if( heap_data == true )
	{
		free( (void*)*(uintptr_t*)(node->data) );
	}

	node->next = NULL;
	node->prev = NULL;

	free(node);

	list->length--;

	return true;
}

bool LinkedList_remove_from(LinkedList_List *list, LinkedList_Node* from, LinkedList_Node* to, bool heap_data)
{
	bool remove_status = true;
	LinkedList_Node* temp = from;

	while(temp != to)
	{
		temp = from;
		from = from->next;

		remove_status = LinkedList_remove(list, temp, heap_data);

		if(remove_status == false)
			return false;
	}

	return true;
}

void LinkedList_clean(LinkedList_List *list, bool heap_data)
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