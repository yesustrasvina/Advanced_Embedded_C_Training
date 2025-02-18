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

typedef struct scheduler
{
    uint32_t tick;          /*the time base in ms*/
    uint32_t timeout;       /*the number of milliseconds the scheduler should run*/
    uint8_t tasks;         /*number of task to handle*/
    uint8_t tasksCount;    /*internal task counter*/
    Task_TypeDef *taskPtr;  /*Pointer to buffer for the TCB tasks*/
}Scheduler_HandleTypeDef;


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

void runInit(Scheduler_HandleTypeDef *hscheduler);

/*********** Test functions ***********/
void test_HIL_SCHEDULER_InitScheduler(void);
void test_HIL_SCHEDULER_RegisterTask(void);
void test_HIL_SCHEDULER_StopTask(void);
void test_HIL_SCHEDULER_StartTask(void);
void test_HIL_SCHEDULER_PeriodTask(void);