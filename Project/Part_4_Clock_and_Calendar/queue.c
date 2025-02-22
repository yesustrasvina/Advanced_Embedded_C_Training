#include "queue.h"

void HIL_QUEUE_InitQueue( QUEUE_HandleTypeDef *hqueue )
{
    hqueue->Head = 0;
    hqueue->Tail = 0;
    hqueue->Empty = TRUE;
    hqueue->Full = FALSE;
}

uint8_t HIL_QUEUE_WriteData( QUEUE_HandleTypeDef *hqueue, void *data )
{
    if(hqueue->Full == TRUE)
    {
        return FALSE;
    }
    else
    {
        uint8_t *buffer = (uint8_t*) hqueue->Buffer;
        memcpy(buffer + (hqueue->Head * hqueue->Size), data, hqueue->Size);

        hqueue->Empty = FALSE;
        hqueue->Head = ( hqueue->Head + 1 ) % hqueue->Elements;

        if(hqueue->Head == hqueue->Tail)
        {
            hqueue->Full = TRUE;
        }
        return TRUE;
    }
}

uint8_t HIL_QUEUE_ReadData( QUEUE_HandleTypeDef *hqueue, void *data )
{
    if(hqueue->Empty == TRUE)
    {
        return FALSE;
    }
    else
    {
        uint8_t *buffer = (uint8_t*) hqueue->Buffer;
        memcpy(data, &buffer[hqueue->Tail * hqueue->Size], hqueue->Size);

        hqueue->Tail = ( hqueue->Tail + 1 ) % hqueue->Elements;
        // 1 % 7 = 1
        // 2 % 7 = 2
        // 7 % 7 = 0
        hqueue->Full = FALSE;
        if(hqueue->Tail == hqueue->Head)
        {
            hqueue->Empty = TRUE;
        }
        return TRUE;
    }
}

uint8_t HIL_QUEUE_IsQueueEmpty( QUEUE_HandleTypeDef *hqueue )
{
    return hqueue->Empty;
}

void HIL_QUEUE_FlushQueue( QUEUE_HandleTypeDef *hqueue )
{
    if(hqueue->Empty == FALSE)
    {
        hqueue->Empty = TRUE;
        hqueue->Full = FALSE;
        hqueue->Head = 0;
        hqueue->Tail = 0;
    }
    #ifdef DEBUG
    printf("Prueba");
    #endif
}


/*********** Unit test functions ***********/
void test_HIL_QUEUE_InitQueue( void )
{
    MsgType_Message buffer [ 10U ]; // Array of then element to use as queue memory space
    QUEUE_HandleTypeDef Queue; // Queue control structure

    Queue.Buffer = ( void* ) buffer; // Set the buffer var as the own queue buffer
    Queue.Elements = 10U; // Queue lenght, must be the same or less than array buffer size
    Queue.Size = sizeof( MsgType_Message ); // Size of the elements to handle
    HIL_QUEUE_InitQueue( &Queue ); //Init Queue

    assert(Queue.Head == 0);
    assert(Queue.Tail == 0);
    assert(Queue.Full == FALSE);
    assert(Queue.Empty == TRUE);
    printf("Test Queue initialization passed\n");
}

void test_HIL_QUEUE_WriteData( void )
{
    MsgType_Message MsgToWrite;


    MsgType_Message buffer [ 10U ]; // Array of then element to use as queue memory space
    QUEUE_HandleTypeDef Queue; // Queue control structure

    Queue.Buffer = ( void* ) buffer; // Set the buffer var as the own queue buffer
    Queue.Elements = 10U; // Queue lenght, must be the same or less than array buffer size
    Queue.Size = sizeof( MsgType_Message ); // Size of the elements to handle
    HIL_QUEUE_InitQueue( &Queue ); //Init Queue

    // Write message
    MsgToWrite.msg  = 1;
    MsgToWrite.value = 100U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );

    assert(Queue.Elements == 10);
    assert(MsgToWrite.msg == 1);
    assert(MsgToWrite.value == 100);
    assert(Queue.Empty == FALSE);
    printf("Test Queue Write Data passed\n");
}

void test_HIL_QUEUE_WriteData_FillBuffer( void )
{
    MsgType_Message MsgToWrite;

    MsgType_Message buffer [ 3U ]; // Array of then element to use as queue memory space
    QUEUE_HandleTypeDef Queue; // Queue control structure

    Queue.Buffer = ( void* ) buffer; // Set the buffer var as the own queue buffer
    Queue.Elements = 3U; // Queue lenght, must be the same or less than array buffer size
    Queue.Size = sizeof( MsgType_Message ); // Size of the elements to handle
    HIL_QUEUE_InitQueue( &Queue ); //Init Queue

    // Write message
    MsgToWrite.msg  = 1;
    MsgToWrite.value = 100U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
    // Write message
    MsgToWrite.msg  = 2;
    MsgToWrite.value = 200U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
    // Write message
    MsgToWrite.msg  = 3;
    MsgToWrite.value = 150U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );

    assert(Queue.Elements == 3);
    assert(Queue.Empty == FALSE);
    assert(Queue.Full == TRUE);
    printf("Test Queue Write Data Full Buffer passed\n");
}

void test_HIL_QUEUE_FlushQueue( void )
{
    MsgType_Message MsgToWrite;

    MsgType_Message buffer [ 3U ]; // Array of then element to use as queue memory space
    QUEUE_HandleTypeDef Queue; // Queue control structure

    Queue.Buffer = ( void* ) buffer; // Set the buffer var as the own queue buffer
    Queue.Elements = 3U; // Queue lenght, must be the same or less than array buffer size
    Queue.Size = sizeof( MsgType_Message ); // Size of the elements to handle
    HIL_QUEUE_InitQueue( &Queue ); //Init Queue

    // Write message
    MsgToWrite.msg  = 1;
    MsgToWrite.value = 100U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
    // Write message
    MsgToWrite.msg  = 2;
    MsgToWrite.value = 200U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
    // Write message
    MsgToWrite.msg  = 3;
    MsgToWrite.value = 150U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );

    HIL_QUEUE_FlushQueue( &Queue );

    assert(Queue.Empty == TRUE);
    assert(Queue.Full == FALSE);
    assert(Queue.Head == 0);
    assert(Queue.Tail == 0);

    printf("Test Flush Queue passed\n");
}