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
        hscheduler->taskPtr[hscheduler->tasksCount].elapsed = 0; // Period or 0? if period, task will run automatically in scheduler
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
            runTimer(hscheduler);
            runtask(hscheduler);
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

void runtask(Scheduler_HandleTypeDef *hscheduler)
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

    assert(Sche.taskPtr->running == FALSE);
    assert(Sche.taskPtr->stop == TRUE);
    assert(Sche.tasks == 0);
    assert(Sche.tasksCount == 0);
    printf("Test init passed\n");
}

void test_HIL_SCHEDULER_RegisterTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Task_500ms(void);
    
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

    assert(Sche.taskPtr[0].period == 500);
    assert(Sche.taskPtr[0].running == TRUE);
    assert(Sche.taskPtr[0].stop == FALSE);
    assert(Sche.tasksCount == 2);
    assert(Sche.taskPtr[0].initFunc == Init_500ms);
    printf("Register test passed\n");
}

void test_HIL_SCHEDULER_StopTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Task_500ms(void);
    
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
    HIL_SCHEDULER_StopTask( &Sche, 1);

    assert(Sche.taskPtr[0].running == FALSE);
    assert(Sche.taskPtr[0].stop == TRUE);
    printf("Stop task test passed\n");
}

void test_HIL_SCHEDULER_StartTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Task_500ms(void);
    
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
    HIL_SCHEDULER_StartTask( &Sche, 1);

    assert(Sche.taskPtr[0].running == TRUE);
    assert(Sche.taskPtr[0].stop == FALSE);
    printf("Start task test passed\n");
}

void test_HIL_SCHEDULER_PeriodTask(void)
{
    static Task_TypeDef tasks[ 2 ];
    static Scheduler_HandleTypeDef Sche;

    void Init_500ms(void);
    void Task_500ms(void);
    
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
    HIL_SCHEDULER_PeriodTask( &Sche, 1, 400 );

    assert(Sche.taskPtr[0].period == 400);
    printf("Period test passed\n");
}

/******************************** Timers Functions ********************************/

uint8_t HIL_SCHEDULER_RegisterTimer( Scheduler_HandleTypeDef *hscheduler, uint32_t timeout, void (*callbackPtr)(void) )
{
   uint8_t timer = 0;
   
   if( (hscheduler->timerCounter < hscheduler->timers) && (timeout >= hscheduler->tick) && ((timeout % hscheduler->tick) == 0) ) 
   {
        hscheduler->timerPtr[hscheduler->timerCounter].timeout = timeout;
        hscheduler->timerPtr[hscheduler->timerCounter].count = 0U;
        hscheduler->timerPtr[hscheduler->timerCounter].callbackPtr = callbackPtr;
        hscheduler->timerPtr[hscheduler->timerCounter].startFlag = FALSE;
        hscheduler->timerCounter++;
        timer = hscheduler->timerCounter;
   }
   return timer;
}

uint32_t HIL_SCHEDULER_GetTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer )
{
    uint32_t time;
    if( (timer > 0) && (timer <= hscheduler->timerCounter) )
    {
        time = hscheduler->timerPtr[timer - 1].count; //timerPtr[timer - 1] cause array begins in [0]
    }
    return time;
}

uint8_t HIL_SCHEDULER_ReloadTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer, uint32_t timeout )
{
    uint8_t reload = FALSE;

    if( (timer > 0) && (timer <= hscheduler->timerCounter) )
    {
        hscheduler->timerPtr[timer].timeout = timeout;
        if(hscheduler->timerPtr[timer - 1].startFlag == TRUE)
        {
            hscheduler->timerPtr[timer - 1].count = timeout;
        }
        reload = TRUE;
    }
    return reload;
}

uint8_t HIL_SCHEDULER_StartTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer )
{
    uint8_t start = FALSE;
    uint32_t tickstart = milliseconds();

    if( (timer > 0) && (timer <= hscheduler->timerCounter) )
    {
        hscheduler->timerPtr[timer - 1].count = hscheduler->timerPtr[timer - 1].timeout;
        hscheduler->timerPtr[timer - 1].startFlag = TRUE;
        start = TRUE;
    }
    return start;
}

uint8_t HIL_SCHEDULER_StopTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer )
{
    uint8_t stop = FALSE;

    if( (timer > 0) && (timer <= hscheduler->timerCounter) )
    {
        hscheduler->timerPtr[timer - 1].startFlag = FALSE;
        stop = TRUE;
    }
    return stop;
}

void runTimer (Scheduler_HandleTypeDef *hscheduler)
{
    for(uint8_t i = 0; i < hscheduler->timerCounter; i++)
    {
        if (hscheduler->timerPtr[i].startFlag == TRUE)
        {
            hscheduler->timerPtr[i].count -= hscheduler->tick; //Decrement timer by tick value

            if(hscheduler->timerPtr[i].count == 0) //If timeout stop timer
            {
                hscheduler->timerPtr[i].startFlag = FALSE;

                if(hscheduler->timerPtr[i].callbackPtr != NULL) //If callback exist
                {
                    hscheduler->timerPtr[i].callbackPtr(); //Run callback function
                }
            }
        }
        
    }
}

