/*
Write a function to validate time in 24 hour format, the function will receive as parameters the hour,minutes and seconds.
It shall return a 1 if the parameters makes a valid time or zero if not
*/

#include <stdio.h>

unsigned char Validate_Time( unsigned char hour, unsigned char minutes, unsigned char seconds ); 

int main( void )
{
    unsigned char hour, minutes, seconds;

    if(Validate_Time(hour,minutes,seconds))
        printf("Format is valid.\n");
    else
    printf("Format is invalid.\n");
    

}

unsigned char Validate_Time( unsigned char hour, unsigned char minutes, unsigned char seconds )
{
    printf("Enter hour: ");
    scanf("%u", &hour);
    if(hour <= 24)
    {
        printf("Enter minutes: ");
        scanf("%u", &minutes);
        if(minutes <= 60)
        {
            printf("Enter seconds: ");
            scanf("%u", &seconds);
            if(seconds <= 60)
            {
                return 1;
            }
            else{return 0;}
        }
        else{return 0;}
    }
    else{return 0;}
}