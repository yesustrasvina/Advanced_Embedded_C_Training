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
        rtcc->tm_hour = hour;
        if(minutes >= 0 && minutes <= 59)
        {
            rtcc->tm_min = minutes;
            if(seconds >= 0 && seconds <= 59)
            {
                rtcc->tm_sec = seconds;
                set = TRUE;
            }
        }
    }
    
    return set;
}