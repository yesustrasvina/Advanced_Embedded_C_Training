#include "scheduler.h"

void HIL_SCHEDULER_InitScheduler( Scheduler_HandleTypeDef *hscheduler )
{
    hscheduler->tasksCount = 0;
    for(unsigned char i = 0; i < hscheduler->tasks; i++)
    {
        hscheduler->taskPtr[i].running = FALSE;
        hscheduler->taskPtr[i].stop = TRUE;
    }
    
}

uint8_t HIL_SCHEDULER_RegisterTask( Scheduler_HandleTypeDef *hscheduler, void (*initPtr)(void), void (*taskPtr)(void), uint32_t period )
{
    uint8_t task = 0;
    if( (taskPtr != NULL) && (period >= hscheduler->tick) && ((period % hscheduler->tick) == 0) )
    {
        hscheduler->taskPtr[hscheduler->tasksCount].initFunc = initPtr;
        hscheduler->taskPtr[hscheduler->tasksCount].taskFunc = taskPtr;
        hscheduler->taskPtr[hscheduler->tasksCount].period = period;
        hscheduler->taskPtr[hscheduler->tasksCount].elapsed = 0; // Period or 0?
        hscheduler->taskPtr[hscheduler->tasksCount].running = TRUE;
        hscheduler->taskPtr[hscheduler->tasksCount].stop = FALSE;
        hscheduler->tasksCount++;
        task = hscheduler->tasksCount; 
    }
    return task;
}

uint8_t HIL_SCHEDULER_StopTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task )
{
    uint8_t stop = FALSE;
    if(hscheduler != NULL)
    {
        hscheduler->taskPtr[task - 1].stop = TRUE;
        hscheduler->taskPtr[task - 1].running = FALSE;
        stop = TRUE;
    }
    return stop;
}

uint8_t HIL_SCHEDULER_StartTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task )
{
    uint8_t start = FALSE;
    if(hscheduler != NULL)
    {
        hscheduler->taskPtr[task - 1].stop = FALSE;
        hscheduler->taskPtr[task - 1].running = TRUE;
        start = TRUE;
    }
    return start;
}

uint8_t HIL_SCHEDULER_PeriodTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task, uint32_t period )
{
    uint8_t stop = FALSE;
    hscheduler->taskPtr[task - 1].period = period;
    if(hscheduler->taskPtr[task - 1].stop == TRUE)
    {
        stop = TRUE;
    }
    return stop;
}

long milliseconds( void )
{
    return clock() / ( CLOCKS_PER_SEC / 1000 );
}

void HIL_SCHEDULER_StartScheduler( Scheduler_HandleTypeDef *hscheduler )
{
    uint32_t tickstart = milliseconds();
    runInit(hscheduler);

    do
    {
        if( (milliseconds() - tickstart) >= hscheduler->tick )
        {
            for (uint8_t i = 0; i < hscheduler->tasksCount; i++)
            {
                if(hscheduler->taskPtr[i].running == TRUE && hscheduler->taskPtr[i].stop == FALSE) //Check if its not stopped
                {
                    if(hscheduler->taskPtr[i].elapsed >= hscheduler->taskPtr[i].period) // Check if elapsed time is completed
                    {
                        hscheduler->taskPtr[i].elapsed = 0; // Reset elapsed time
                        hscheduler->taskPtr[i].taskFunc(); //Run task
                    }
                }
                hscheduler->taskPtr[i].elapsed += hscheduler->tick;
            }
        }
    } while ( (milliseconds() - tickstart) < hscheduler->timeout );
    
}

void runInit(Scheduler_HandleTypeDef *hscheduler)
{
    for(uint8_t i = 0; i < hscheduler->tasksCount; i++)
    {
        if(hscheduler->taskPtr[i].initFunc != NULL)
        {
            hscheduler->taskPtr[i].initFunc();
        }
    }
}

/*********** Test functions ***********/
void test_HIL_SCHEDULER_InitScheduler(void)
{
    /*init the scheduler with two tasks and a tick time of 100ms and run for 5 seconds only*/
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;
    Sche.tick = 100;
    Sche.tasks = 2;
    Sche.timeout = 5000;
    Sche.taskPtr = tasks;

    HIL_SCHEDULER_InitScheduler( &Sche );

    assert(Sche.tasksCount == 0);

    for(unsigned char i = 0; i < 2; i++)
    {
        assert(Sche.taskPtr[i].stop == TRUE);
        assert(Sche.taskPtr[i].running == FALSE);
    }
    printf("Test init passed\n");
}

void test_HIL_SCHEDULER_RegisterTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Init_1000ms(void);
    void Task_500ms(void);
    void Task_1000ms(void);
    
    unsigned char TaskID1;
    unsigned char TaskID2;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 5 seconds only*/
    Sche.tick = 100;
    Sche.tasks = 2;
    Sche.timeout = 5000;
    Sche.taskPtr = tasks;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*register two task with thier corresponding init functions and their periodicity, 1000ms and 500ms*/
    TaskID1 = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TaskID2 = HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );

    assert(Sche.taskPtr[0].period == 500);
    assert(Sche.taskPtr[1].period == 1000);
    assert(Sche.taskPtr[0].running == TRUE);
    assert(Sche.taskPtr[0].stop == FALSE);
    assert(Sche.taskPtr[1].running == TRUE);
    assert(Sche.taskPtr[1].stop == FALSE);
    assert(Sche.tasksCount == 2);
    assert(Sche.taskPtr[0].initFunc == Init_500ms);
    assert(Sche.taskPtr[1].initFunc == Init_1000ms);
    printf("Register test passed\n");
}

void test_HIL_SCHEDULER_StopTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Init_1000ms(void);
    void Task_500ms(void);
    void Task_1000ms(void);
    
    unsigned char TaskID1;
    unsigned char TaskID2;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 5 seconds only*/
    Sche.tick = 100;
    Sche.tasks = 2;
    Sche.timeout = 5000;
    Sche.taskPtr = tasks;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*register two task with thier corresponding init functions and their periodicity, 1000ms and 500ms*/
    TaskID1 = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TaskID2 = HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );
    HIL_SCHEDULER_StopTask( &Sche, 1);
    HIL_SCHEDULER_StopTask( &Sche, 2);

    assert(Sche.taskPtr[1].running == FALSE);
    assert(Sche.taskPtr[1].stop == TRUE);
    assert(Sche.taskPtr[0].running == FALSE);
    assert(Sche.taskPtr[0].stop == TRUE);
    printf("Stop task test passed\n");
}

void test_HIL_SCHEDULER_StartTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Init_1000ms(void);
    void Task_500ms(void);
    void Task_1000ms(void);
    
    unsigned char TaskID1;
    unsigned char TaskID2;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 5 seconds only*/
    Sche.tick = 100;
    Sche.tasks = 2;
    Sche.timeout = 5000;
    Sche.taskPtr = tasks;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*register two task with thier corresponding init functions and their periodicity, 1000ms and 500ms*/
    TaskID1 = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TaskID2 = HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );
    HIL_SCHEDULER_StartTask( &Sche, 1);
    HIL_SCHEDULER_StartTask( &Sche, 2);

    assert(Sche.taskPtr[1].running == TRUE);
    assert(Sche.taskPtr[1].stop == FALSE);
    assert(Sche.taskPtr[0].running == TRUE);
    assert(Sche.taskPtr[0].stop == FALSE);
    printf("Start task test passed\n");
}

void test_HIL_SCHEDULER_PeriodTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Init_1000ms(void);
    void Task_500ms(void);
    void Task_1000ms(void);
    
    unsigned char TaskID1;
    unsigned char TaskID2;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 5 seconds only*/
    Sche.tick = 100;
    Sche.tasks = 2;
    Sche.timeout = 5000;
    Sche.taskPtr = tasks;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*register two task with thier corresponding init functions and their periodicity, 1000ms and 500ms*/
    TaskID1 = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TaskID2 = HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );
    HIL_SCHEDULER_PeriodTask( &Sche, 1, 400 );
    HIL_SCHEDULER_PeriodTask( &Sche, 2, 900 );

    assert(Sche.taskPtr[0].period == 400);
    assert(Sche.taskPtr[1].period == 900);
    printf("Period test passed\n");
}

