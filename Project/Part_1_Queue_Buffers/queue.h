#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#define TRUE    1
#define FALSE   0


typedef struct
{
    void        *Buffer;  //pointer to array that store buffer data
    uint32_t    Elements; //number of elements to store (the queue lenght) 
    uint8_t     Size;     //size of the elements to store
    uint8_t     Head;     //variable to signal the next queue space to write 
    uint8_t     Tail;     //variable to signal the next queue space to read
    uint8_t     Empty;    //flag to indicate if the queue is empty
    uint8_t     Full;     //flag to indicate if the queue is full
} QUEUE_HandleTypeDef;

typedef struct 
{
    uint8_t msg;
    uint8_t value;
}MsgType_Message;

/* Initialization function*/
void HIL_QUEUE_InitQueue( QUEUE_HandleTypeDef *hqueue );

/* Write data function */
uint8_t HIL_QUEUE_WriteData( QUEUE_HandleTypeDef *hqueue, void *data );

/* Read data function */
uint8_t HIL_QUEUE_ReadData( QUEUE_HandleTypeDef *hqueue, void *data );

/* Check if is queue empty function */
uint8_t HIL_QUEUE_IsQueueEmpty( QUEUE_HandleTypeDef *hqueue );

/* Function to flush queue */
void HIL_QUEUE_FlushQueue( QUEUE_HandleTypeDef *hqueue );


/*********** Unit test functions ***********/
void test_HIL_QUEUE_InitQueue( void );
void test_HIL_QUEUE_WriteData( void );
void test_HIL_QUEUE_WriteData_FillBuffer( void );
void test_HIL_QUEUE_FlushQueue( void );