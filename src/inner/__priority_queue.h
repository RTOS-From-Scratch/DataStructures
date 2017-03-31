#ifndef INNER_PRIORITY_QUEUE
#define INNER_PRIORITY_QUEUE

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef size_t PQueue_nodeIndex;

typedef struct __PQueue_Node {
    int8_t priority;
    void* data;
} __PQueue_Node;

typedef struct __PQueue {
    size_t length;
    long curr_index;
    __PQueue_Node queue[];
}__PQueue;

void __exchange_node(__PQueue_Node * node1, __PQueue_Node * node2 );
void __swim_LastElement( __PQueue *queue );
void __PQueue_Node_sink( __PQueue *p_queue, PQueue_nodeIndex index );
void __swim_LastElement_inverted( __PQueue *queue );
void __sink_LastElement_inverted( __PQueue *queue );
void* __PQueue_popHead(__PQueue *p_queue);
void __PQueue_Node_move(__PQueue_Node * src, __PQueue_Node * dest);

#endif // INNER_PRIORITY_QUEUE
