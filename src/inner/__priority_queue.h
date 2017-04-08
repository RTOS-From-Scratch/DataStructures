#ifndef INNER_PRIORITY_QUEUE
#define INNER_PRIORITY_QUEUE

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct __PQueue_Node {
    int8_t priority;
    void* data;
} __PQueue_Node;

typedef struct __PQueue {
    uint16_t length;
    int16_t curr_index;
    __PQueue_Node queue[];
}__PQueue;

void __exchange_node(__PQueue_Node * node1, __PQueue_Node * node2 );
void __swim_LastElement( __PQueue *queue );
void __PQueue_Node_sink( __PQueue *p_queue, uint16_t index );
void __swim_LastElement_inverted( __PQueue *queue );
void __IPQueue_Node_sink(__PQueue *p_queue_inv, uint16_t index );
void* __PQueue_popHead(__PQueue *p_queue);
void __PQueue_Node_move(__PQueue_Node * src, __PQueue_Node * dest);
int16_t __PQueue_find(__PQueue *p_queue, void* data);

#endif // INNER_PRIORITY_QUEUE
