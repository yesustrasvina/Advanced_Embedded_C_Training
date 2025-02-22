#include "scheduler.h"

typedef union _AppRtcc_Ctrl
{
    uint8_t Register;   /*8 bit vaiable*/
    struct _bits
    {
        uint8_t clk_en : 1;     /*!< clock enable flag      */
        uint8_t al_set : 1;     /*!< alarm set flag         */
        uint8_t al_active : 1;  /*!< alarm active flag      */
        uint8_t none : 4;
    } bits;
} AppRtcc_Ctrl;

typedef struct _AppRtcc_Clock 
{
    uint8_t tm_sec;         /*!< seconds,  range 0 to 59          */
    uint8_t tm_min;         /*!< minutes, range 0 to 59           */
    uint8_t tm_hour;        /*!< hours, range 0 to 23             */
    uint8_t tm_mday;        /*!< day of the month, range 1 to 31  */
    uint8_t tm_mon;         /*!< month, range 1 to 12             */
    uint16_t tm_year;       /*!< years in rage 1900 2100          */
    uint8_t tm_wday;        /*!< day of the week, range 0 to 6    */
    uint8_t al_min;         /*!< alarm minutes, range 0 to 59     */
    uint8_t al_hour;        /*!< alarm hours, range 0 to 23       */
    uint8_t mt_days[13u];   /*!< max days on each month */
    AppRtcc_Ctrl ctrl;      /*!< clock control bits */
} AppRtcc_Clock;

/*  Interface to initialize the internal clock structure */
void AppRtcc_clockInit( AppRtcc_Clock *rtcc );

/* Interface to set a new time */
uint8_t AppRtcc_setTime( AppRtcc_Clock *rtcc, uint8_t hour, uint8_t minutes, uint8_t seconds );

/* Interface to set a new date */
uint8_t AppRtcc_setDate( AppRtcc_Clock *rtcc, uint8_t day, uint8_t month, uint16_t year );