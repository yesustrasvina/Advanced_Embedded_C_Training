#include "Rtcc.h"

#define ENABLE 1
#define DISABLE 0

void AppRtcc_clockInit( AppRtcc_Clock *rtcc )
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

uint8_t AppRtcc_setTime( AppRtcc_Clock *rtcc, uint8_t hour, uint8_t minutes, uint8_t seconds )
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

uint8_t AppRtcc_setDate( AppRtcc_Clock *rtcc, uint8_t day, uint8_t month, uint16_t year )
{
    uint8_t set = FALSE;
    if(year >= 1900 && year <= 2100)
    {
        if(month >= 1 && month <= 12)
        {
            if(month == 2)
            {
                if(day >= 1 && day <= 28)
                {
                    rtcc->tm_year = year;
                    rtcc->tm_mon = month;
                    rtcc->tm_mday = day;
                    set = TRUE;
                }
            }
            else if(month == 1 | month == 3 | month == 5 | month == 7 | month == 8 | month == 10 | month == 12 )
            {
                if(day >= 1 && day <= 31)
                {
                    rtcc->tm_year = year;
                    rtcc->tm_mon = month;
                    rtcc->tm_mday = day;
                    set = TRUE;
                }
                
            }
            else if(month == 4 | month == 6 | month == 9 | month == 11 )
            {
                if(day >= 1 && day <= 30)
                {
                    rtcc->tm_year = year;
                    rtcc->tm_mon = month;
                    rtcc->tm_mday = day;
                    set = TRUE;
                }
                
            }
        }
    }
    return set;
}