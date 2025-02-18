/*
Write a function to validates date in day of the month, month (from 1 to 12) and year (four digits from 1900 to 2100) format,
the function will receive as parameters the date. It shall return a 1 if the parameters makes a valid date or zero if not.
The leap years shall be take into consideration
*/

#include <stdio.h>

unsigned char Validate_Date( unsigned char days, unsigned char month, unsigned short year );

int main( void )
{
    unsigned char days, month, year;

    if(Validate_Date( days, month, year ))
    {
        printf("Valid format\n");
    }
    else
    {
        printf("Invalid format\n");
    }

    return 0;
}

unsigned char Validate_Date( unsigned char days, unsigned char month, unsigned short year )
{
    printf("Enter the year: ");
    scanf("%u", &year);
    if(year >= 1900 && year <=2100)
    {
        printf("Enter the month: ");
        scanf("%u", &month);
        if(month >=1 && month <= 12)
        {
            printf("Enter the day: ");
            scanf("%u", &days);
            if(month == 2 && (year % 4) == 0)
            {
                if(days >= 1 && days <=29)
                {
                    return 1;
                }
                else{ return 0; }
            }
            else if(month == 2 && (year % 4) != 0)
            {
                if(days >= 1 && days <=28)
                {
                    return 1;
                }
                else{ return 0; }
            }
            else if(days >= 1 && days <=31)
            {
                return 1;
            }
            else{ return 0; }
        }
        else{ return 0; }
    }
    else{ return 0; }
}