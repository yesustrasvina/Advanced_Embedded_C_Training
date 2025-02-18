#include <stdio.h>
#include <assert.h>

#define FALSE 0
#define TRUE 1

/* Control structure of the buffer */
typedef struct
{
    unsigned char *Buffer;
    unsigned long Elements;
    unsigned long Head;
    unsigned long Tail;
    unsigned char Empty;
    unsigned char Full;
} AppBuffer_Buffer;

/* Initialize buffer*/
void AppBuffer_initBuffer( AppBuffer_Buffer *hbuffer );

/* Write data */
void AppBuffer_writeData( AppBuffer_Buffer *hbuffer, unsigned char data );

/* Read data */
unsigned char AppBuffer_readData( AppBuffer_Buffer *hbuffer );

/* Check if buffer is empty */
unsigned char AppBuffer_isBufferEmpty( AppBuffer_Buffer *hbuffer );



/***************  Unit test functions ***************/
void test__AppBuffer_initBuffer__buffer_intialization( void );
void test__AppBuffer_writeData__writting_a_single_data( void );
void test__AppBuffer_writeData__filling_the_buffer( void );