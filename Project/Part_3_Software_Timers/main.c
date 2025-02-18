#include "scheduler.h"

#define TASKS_N     1
#define TIMERS_N    1
#define TICK_VAL    100

static Task_TypeDef tasks[ TASKS_N ];
static Timer_TypeDef timers[TIMERS_N];
static Scheduler_HandleTypeDef Sche;
static unsigned char TimerID;

void Init_500ms(void);
void Task_500ms(void);
void Callback(void);


int main( void )
{
    unsigned char TaskID;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 3 seconds only*/
    Sche.tick = TICK_VAL;
    Sche.tasks = TASKS_N;
    Sche.timeout = 3000;
    Sche.taskPtr = tasks;
    Sche.timers = TIMERS_N;
    Sche.timerPtr = timers;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*Register task*/
    TaskID = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TimerID = HIL_SCHEDULER_RegisterTimer( &Sche, 1000U, Callback );
    
    HIL_SCHEDULER_StartTimer( &Sche, TimerID );

    /*run the scheduler for the mount of time stablished in Sche.timeout*/
    HIL_SCHEDULER_StartScheduler( &Sche );

    return 0;
}
void Init_500ms(void)
{
    printf("Init task 500 millisecond");
}

void Task_500ms(void)
{
    static int loop = 0;
    //printf("This is a counter from task 500ms: %d", loop++);
}

void Callback(void)
{
    static int loop = 0;
    //printf("This is a counter from timer callback: %d", loop++);
    HIL_SCHEDULER_StartTimer( &Sche, TimerID );
}