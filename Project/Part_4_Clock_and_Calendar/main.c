#include "scheduler.h"
#include "Rtcc.h"
#include "queue.h"
/**
 * @brief   message to be used for intercomunicate both tasks
*/
typedef struct
{
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
    uint8_t day;
    uint8_t wday;
    uint8_t month;
    uint16_t year;
}Message;
#define TASKS_N     2
#define TICK_VAL    100
static Task_TypeDef tasks[ TASKS_N ];
static Scheduler_HandleTypeDef Sche;
static AppRtcc_Rtcc rtccClock;
static QUEUE_HandleTypeDef rtccQueue;
void Init_500ms(void);
void Init_1000ms(void);
void Task_500ms(void);
void Task_1000ms(void);
int main( void )
{
    static Message Messages[6u];
    /*create the queue to store as max 6 items*/
    rtccQueue.Buffer = Messages;
    rtccQueue.Elements = 6;
    rtccQueue.Size = sizeof( Message );
    HIL_QUEUE_InitQueue( &rtccQueue );
    /*init the scheduler with two tasks and a tick time of 100ms and run for 10 seconds only*/
    Sche.tick = TICK_VAL;
    Sche.tasks = TASKS_N;
    Sche.taskPtr = tasks;
    Sche.timeout = 10000;
    HIL_SCHEDULER_InitScheduler( &Sche );
    /*register two task with thier corresponding init fucntions and their periodicyt, 100ms and 500ms*/
    HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );
    /*run the scheduler for the mount of time stablished in Sche.timeout*/
    HIL_SCHEDULER_StartScheduler( &Sche );
    return 0;
}
/**
 * @brief   Init task for 500ms task
 * 
 * Print a message to the console to indicate that the task is running
*/
void Init_500ms(void)
{
    printf("Init task 500 millisecond\n");
}
/**
 * @brief   Init task for 1000ms task
 * 
 * Print a message to the console to indicate that the task is running
 * and init the clock to 12:30:00 24/6/1984
*/
void Init_1000ms(void)
{
    AppRtcc_clockInit( &rtccClock );
    AppRtcc_setTime( &rtccClock, 12, 30, 0 );
    AppRtcc_setDate( &rtccClock, 24, 6, 1984 );
    printf("Init task 1000 millisecond\n");
}
/**
 * @brief   500ms task
 * 
 * Read the queue and print the time and date if a new message arrives
*/
void Task_500ms(void)
{
    Message msgToRead;
    /*Query if a new message arrive from the queue*/
    if( HIL_QUEUE_IsQueueEmpty( &rtccQueue ) == 0 )
    {
        /*Read the message in the queue*/
        HIL_QUEUE_ReadData( &rtccQueue, &msgToRead );
        printf("Time - %d:%d:%d\n", msgToRead.hour, msgToRead.minutes, msgToRead.seconds );
        printf("Date - %d/%d/%d\n", msgToRead.day, msgToRead.month, msgToRead.year );
    }
}
/**
 * @brief   1000ms task
 * 
 * Poll the Rtcc periodic task and get the time and date from the clock and send it to 
 * the 500ms task using a queue
*/
void Task_1000ms(void)
{
    Message msgToWrite;
    /*Clock periodic task*/
    AppRtcc_periodicTask( &rtccClock );
    /*get time and date*/
    AppRtcc_getTime( &rtccClock, &msgToWrite.hour, &msgToWrite.minutes, &msgToWrite.seconds );
    AppRtcc_getDate( &rtccClock, &msgToWrite.day, &msgToWrite.month, &msgToWrite.year, &msgToWrite.wday );
    /*send time and date to 500ms task using a queue*/
    HIL_QUEUE_WriteData( &rtccQueue, &msgToWrite );
}