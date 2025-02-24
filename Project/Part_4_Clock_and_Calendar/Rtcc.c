#include "Rtcc.h"

#define ENABLE 1
#define DISABLE 0


void AppRtcc_clockInit( AppRtcc_Rtcc *rtcc )
{
    rtcc->tm_sec = 0;
    rtcc->tm_min = 0;
    rtcc->tm_hour = 0;
    rtcc->tm_mday = 1;
    rtcc->tm_mon = 1;
    rtcc->tm_year = 1900;
    rtcc->ctrl.bits.clk_en = ENABLE;
    rtcc->ctrl.bits.al_active = DISABLE;
    rtcc->ctrl.bits.al_set = DISABLE;
}


uint8_t AppRtcc_setTime( AppRtcc_Rtcc *rtcc, uint8_t hour, uint8_t minutes, uint8_t seconds )
{
    uint8_t set = FALSE;

    if(hour >= 0 && hour <= 23)
    {
        if(minutes >= 0 && minutes <= 59)
        {
            if(seconds >= 0 && seconds <= 59)
            {
                rtcc->tm_hour = hour;
                rtcc->tm_min = minutes;
                rtcc->tm_sec = seconds;
                set = TRUE;
            }
        }
    }
    return set;
}

uint8_t AppRtcc_setDate( AppRtcc_Rtcc *rtcc, uint8_t day, uint8_t month, uint16_t year )
{
    uint8_t set = FALSE;

    // Set default values for the days in each month
    rtcc->mt_days[0] = 31; rtcc->mt_days[1] = 28; rtcc->mt_days[2] = 31;
    rtcc->mt_days[3] = 30; rtcc->mt_days[4] = 31; rtcc->mt_days[5] = 30;
    rtcc->mt_days[6] = 31; rtcc->mt_days[7] = 31; rtcc->mt_days[8] = 30;
    rtcc->mt_days[9] = 31; rtcc->mt_days[10] = 30; rtcc->mt_days[11] = 31;

    // Handle leap year for February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        rtcc->mt_days[1] = 29; // February in a leap year
    }

    if(year >= 1900 && year <= 2100)
    {
        if(month >= 1 && month <= 12)
        {
            if(day >= 1 && day <= rtcc->mt_days[month - 1]) // Ensure the day is valid for the month
            {
                rtcc->tm_year = year;
                rtcc->tm_mon = month;
                rtcc->tm_mday = day;
                set = TRUE;
            }
        }
    }

    return set;
}

uint8_t AppRtcc_setAlarm( AppRtcc_Rtcc *rtcc, uint8_t hour, uint8_t minutes )
{
    uint8_t set = FALSE;
    if(hour >= 0 && hour <= 23)
    {
        if(minutes >= 0 && minutes <= 59)
        {
            rtcc->al_hour = hour;
            rtcc->al_min = minutes;
            rtcc->ctrl.bits.al_set = TRUE;
            set = TRUE;
        }
    }
    return set;
}

void AppRtcc_getTime( AppRtcc_Rtcc *rtcc, uint8_t *hour, uint8_t *minutes, uint8_t *seconds )
{
    *hour = rtcc->tm_hour;
    *minutes = rtcc->tm_min;
    *seconds = rtcc->tm_sec;
}

void AppRtcc_getDate( AppRtcc_Rtcc *rtcc, uint8_t *day, uint8_t *month, uint16_t *year, uint8_t *weekDay )
{
    *day = rtcc->tm_mday;
    *month = rtcc->tm_mon;
    *year = rtcc->tm_year;

    // Calculate the day of the week using Zeller's Congruence
    int d = *day;
    int m = *month;
    int y = *year;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int k = y % 100;
    int j = y / 100;

    int f = d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    
    *weekDay = rtcc->tm_wday = f % 7; // Weekday: 0 = Saturday, 1 = Sunday, ..., 6 = Friday
}

uint8_t AppRtcc_getAlarm( AppRtcc_Rtcc *rtcc, uint8_t *hour, uint8_t *minutes )
{
    *hour = rtcc->al_hour;
    *minutes = rtcc->al_min;
}

void AppRtcc_clearAlarm( AppRtcc_Rtcc *rtcc )
{
    if( (rtcc->al_hour == rtcc->tm_hour) && (rtcc->al_min == rtcc->tm_min) )
    {
        rtcc->ctrl.bits.al_active = FALSE;
        AppRtcc_setAlarm(rtcc, 0, 0);
    }
}

uint8_t AppRtcc_getAlarmFlag( AppRtcc_Rtcc *rtcc )
{
    uint8_t set = FALSE;
    if(rtcc->ctrl.bits.al_active == TRUE)
    {
        set = TRUE;
    }
    return set;
}

void AppRtcc_periodicTask( AppRtcc_Rtcc *rtcc )
{
    rtcc->tm_sec++;
    if(rtcc->tm_sec == 60)
    {
        rtcc->tm_min++;
        rtcc->tm_sec = 00;
        if(rtcc->tm_min == 60)
        {
            rtcc->tm_hour++;
            rtcc->tm_min = 00;
            if(rtcc->tm_hour == 24)
            {
                rtcc->tm_mday++;
                rtcc->tm_hour = 00;
                if(rtcc->tm_mday > rtcc->mt_days[(rtcc->tm_mon) - 1])
                {
                    rtcc->tm_mon++;
                    rtcc->tm_mday = 1;
                    if(rtcc->tm_mon > 12)
                    {
                        rtcc->tm_year++;
                        rtcc->tm_mon = 1;
                    }
                }
            }
        }
    }
}