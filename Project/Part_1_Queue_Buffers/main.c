#include "queue.h"

 int main( void )
 {

    test_HIL_QUEUE_InitQueue();
    test_HIL_QUEUE_WriteData();
    test_HIL_QUEUE_WriteData_FillBuffer();
    test_HIL_QUEUE_FlushQueue();

    MsgType_Message MsgToWrite;
    MsgType_Message MsgToRead;

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
    // Write message
    MsgToWrite.msg  = 2;
    MsgToWrite.value = 200U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
     // Write message
    MsgToWrite.msg  = 3;
    MsgToWrite.value = 255U;
    HIL_QUEUE_WriteData( &Queue, &MsgToWrite );
    
    //Read all the messages
    while( HIL_QUEUE_IsQueueEmpty ( &Queue ) == FALSE )
    {
        HIL_QUEUE_ReadData( &Queue, &MsgToRead );
        printf("Msg read form the queue %d\n", MsgToRead.msg);
        printf("Value read from the queue %d\n", MsgToRead.value);
    }
    

    return 0;
 }