#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define DOUBLE__LINKEDLIST

int main()
{
	Stack *stack = Stack_new();
	// int val = 0;
// 	int* ptr;

	for( int iii = 0; iii < 10; iii++ )
	{
// 		ptr = malloc(4 * sizeof(int));
		// printf("PTR:\t%p\n", ptr);
// 		*ptr = iii;
		Stack_push( stack, &iii, sizeof(iii) );
	}

// 	LinkedList_Node* node = LinkedList_getBegin(list);
	// LinkedList_Node* tail = LinkedList_getLast(list);
	// printf("%d\n", *(int*)LinkedList_getData(head));
	// LinkedList_Node* node = LinkedList_next(node2);

	// LinkedList_removeFrom(list, head, tail, true);
	// LinkedList_remove(list, LinkedList_next(node), false);

	printf("%d\n", *(int *)Stack_pop(stack));
    printf("%d\n", *(int *)Stack_pop(stack));
    printf("%d\n", *(int *)Stack_pop(stack));
    printf("%d\n", *(int *)Stack_pop(stack));

	printf("%lu\n", Stack_getLength(stack));

	// for(LinkedList_Node* node = LinkedList_getBegin(list); node != NULL; node = LinkedList_next(node))
	// {
	// 	printf("%d\n", *(int *)LinkedList_getData(node));
		// node = LinkedList_next(node);
	// }

	Stack_clean(stack, false);
	// printf("%lu\n", LinkedList_getLength(list));

	return 0;
}
