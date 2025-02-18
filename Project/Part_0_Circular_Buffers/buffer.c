#include "buffer.h"

void AppBuffer_initBuffer( AppBuffer_Buffer *hbuffer )
{
    hbuffer->Head = 0;
    hbuffer->Tail = 0;
    hbuffer->Empty = TRUE;
    hbuffer->Full = FALSE;
}

void AppBuffer_writeData( AppBuffer_Buffer *hbuffer, unsigned char data )
{
    if(hbuffer->Full == TRUE) // Check if buffer is full first
    {
        printf("Buffer is full. No data written.\n");
        return;
    }
    else
    {
        hbuffer->Buffer[hbuffer->Head] = data;
        hbuffer->Empty = FALSE;
        hbuffer->Head = (hbuffer->Head + 1 ) % hbuffer->Elements;

        if(hbuffer->Head == hbuffer->Tail)
        {
            hbuffer->Full = TRUE;
        }
    }
}

unsigned char AppBuffer_readData( AppBuffer_Buffer *hbuffer )
{
    if(hbuffer->Empty == TRUE)
    {
        printf("Buffer is empty, no data to read.\n");
        return -1;
    }
    else
    {
        unsigned char data =  hbuffer->Buffer[hbuffer->Tail]; //Read the data
        hbuffer->Tail = (hbuffer->Tail + 1) % hbuffer->Elements; //Move tail to next position
        

        if(hbuffer->Tail == hbuffer->Head) //Check if buffer is empty
        {
            hbuffer->Empty = TRUE; //Update empty flag
        }

        hbuffer->Full = FALSE; //Update full flag

        return data;        
    }
}

unsigned char AppBuffer_isBufferEmpty( AppBuffer_Buffer *hbuffer )
{
    if(hbuffer->Empty == TRUE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/***************  Unit test functions ***************/

void test__AppBuffer_initBuffer__buffer_intialization( void )
{
    AppBuffer_Buffer CircBuffer;
    unsigned char arreglo[200];
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 200;

    AppBuffer_initBuffer(&CircBuffer);

    // Test initial conditions
    assert(CircBuffer.Head == 0);  // Head should be 0
    assert(CircBuffer.Tail == 0);  // Tail should be 0
    assert(CircBuffer.Empty == TRUE);  // Buffer should be empty initially
    assert(CircBuffer.Full == FALSE);  // Buffer should not be full
    printf("Test buffer initialization passed\n");
}

void test__AppBuffer_writeData__writting_a_single_data( void )
{
    AppBuffer_Buffer CircBuffer;
    unsigned char arreglo[200];
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 200;
    
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 3u;
    AppBuffer_initBuffer( &CircBuffer );
    AppBuffer_writeData( &CircBuffer, 0x23 );
    assert( CircBuffer.Head == 1 ); //test head pointer increment by one
    assert( arreglo[CircBuffer.Head-1] == 0x23 ); //keep in mind is a circular buffer
    assert( AppBuffer_isBufferEmpty( &CircBuffer ) == FALSE );
    /*if program reach up to here all tested passed*/
    printf("Test writting single data succeed\n");
}

void test__AppBuffer_writeData__filling_the_buffer( void )
{
    AppBuffer_Buffer CircBuffer;
    unsigned char arreglo[200];
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 200;
    
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 3u;
    AppBuffer_initBuffer( &CircBuffer );
    AppBuffer_writeData( &CircBuffer, 0x23 );  //first element
    AppBuffer_writeData( &CircBuffer, 0x23 );  //second element
    AppBuffer_writeData( &CircBuffer, 0x23 );  //third element
    assert( CircBuffer.Full == TRUE );  //test full flag
    assert( CircBuffer.Head == FALSE );  //test head pointer roll over back to zero
    /*if program reach up to here all tested passed*/
    printf("Test filling the buffer succeed\n");
}