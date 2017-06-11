#include "mailbox.h"
#include "Misc/src/definitions.h"
#include <stdlib.h>
#include <string.h>

struct Mailbox
{
    bool isAccessable;
    size_t data_size;
    byte data[];
};

Mailbox* Mailbox_create( size_t size )
{
    Mailbox* mailbox = malloc( sizeof(Mailbox) * size );
    mailbox->isAccessable = true;
    mailbox->data_size = size;

    return mailbox;
}

void* Mailbox_request_read( Mailbox* mailbox )
{
    if(mailbox->isAccessable is false)
        return NULL;

    return mailbox->data;
}

bool Mailbox_request_write( Mailbox* mailbox, void* data )
{
    if(mailbox->isAccessable is false)
        return false;

    mailbox->isAccessable = false;
    memcpy( mailbox->data, data, mailbox->data_size );
    mailbox->isAccessable = true;
    return true;
}
