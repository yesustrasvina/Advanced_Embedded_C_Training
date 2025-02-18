#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct task
{
    uint32_t period;          /*How often the task shopud run in ms*/
    uint32_t elapsed;         /*the current elapsed time*/
    uint8_t running;
    uint8_t stop;
    void (*initFunc)(void);   /*pointer to init task function*/
    void (*taskFunc)(void);   /*pointer to task function*/
}Task_TypeDef;

typedef struct Timer
{
    uint32_t timeout;           /*Timer timeout to decrement and reload when timer is re-started*/
    uint32_t count;             /*Actual timer decrement count*/
    uint8_t startFlag;          /*Flag to start timer count*/
    void(*callbackPtr)(void);   /*Pointer to callback function*/
}Timer_TypeDef;

typedef struct scheduler
{
    uint32_t tick;              /*the time base in ms*/
    uint32_t timeout;           /*the number of milliseconds the scheduler should run*/
    uint8_t tasks;              /*number of task to handle*/
    uint8_t tasksCount;         /*internal task counter*/
    uint8_t timers;             /* Number of software timers to use*/
    uint8_t timerCounter;       /*Counter of timers used*/
    Task_TypeDef *taskPtr;      /*Pointer to buffer for the TCB tasks*/
    Timer_TypeDef *timerPtr;    /*Pointer to buffer timer array*/
}Scheduler_HandleTypeDef;


/****************** Scheduler functions ******************/
/* Initialization function */
void HIL_SCHEDULER_InitScheduler( Scheduler_HandleTypeDef *hscheduler );

/* Register tasks function */
uint8_t HIL_SCHEDULER_RegisterTask( Scheduler_HandleTypeDef *hscheduler, void (*initPtr)(void), void (*taskPtr)(void), uint32_t period );

/* Stop task */
uint8_t HIL_SCHEDULER_StopTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task );

/* Start task */
uint8_t HIL_SCHEDULER_StartTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task );

/* Period task */
uint8_t HIL_SCHEDULER_PeriodTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task, uint32_t period );

/* Start scheduler */
void HIL_SCHEDULER_StartScheduler( Scheduler_HandleTypeDef *hscheduler );

/* Get time function*/
long milliseconds( void );

/* Function to run every task of scheduler */
void runtask(Scheduler_HandleTypeDef *hscheduler);

/* Function to run Initialization functions */
void runInit(Scheduler_HandleTypeDef *hscheduler);

/****************** Timer functions ******************/

/* Register timer */
uint8_t HIL_SCHEDULER_RegisterTimer( Scheduler_HandleTypeDef *hscheduler, uint32_t timeout, void (*callbackPtr)(void) );

/* Get timer */
uint32_t HIL_SCHEDULER_GetTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer );

/* Reload timer */
uint8_t HIL_SCHEDULER_ReloadTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer, uint32_t timeout );

/* Start timer */
uint8_t HIL_SCHEDULER_StartTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer );

/* Stop timer */
uint8_t HIL_SCHEDULER_StopTimer( Scheduler_HandleTypeDef *hscheduler, uint8_t timer );

/* Decrement timer after every tick */
void runTimer (Scheduler_HandleTypeDef *hscheduler);

