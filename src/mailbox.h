#ifndef MAILBOX_H_
#define MAILBOX_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct Mailbox Mailbox;

Mailbox* Mailbox_create( size_t size );
void* Mailbox_request_read( Mailbox* mailbox );
// NOTE: this function copy data to the Mailbox to avoid reference problems
bool Mailbox_request_write( Mailbox* mailbox, void* data );

#endif // MAILBOX_H_
