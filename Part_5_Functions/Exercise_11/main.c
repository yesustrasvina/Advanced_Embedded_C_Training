/*
Write a function to calculate the day of the week from a valid day, month and year.
It will receive a valid date and return the day of the week from Monday (1) to Sunday (7)
 */

#include <stdio.h>

unsigned char WeekDay(unsigned char days, unsigned char month, unsigned short year);
unsigned char Validate_Date(unsigned char day, unsigned char month, unsigned short year);

int main(void) {
    unsigned char day = 0, month = 0, weekday;
    unsigned short year = 0;

    if (Validate_Date(day, month, year)) {
        printf("Valid date\n");
        weekday = WeekDay(day, month, year);
        printf("Day of the week is: %d\n", weekday); // Monday = 1, ..., Sunday = 7
    } else {
        printf("Invalid date\n");
    }

    return 0;
}

unsigned char WeekDay(unsigned char days, unsigned char month, unsigned short year) {
    if (month == 1 || month == 2) {
        month += 12; // Treat January as 13 and February as 14
        year -= 1;   // Decrement the year for these months
    }

    unsigned short century = year / 100;      // Century part of the year
    unsigned short yearPart = year % 100;    // Year part of the year (last two digits)

    // Zeller's Congruence Formula
    int h = (days + (13 * (month + 1)) / 5 + yearPart + (yearPart / 4) + (century / 4) - (2 * century)) % 7;

    unsigned char dayOfWeek = (h + 5) % 7 + 1;

    return dayOfWeek;
}

unsigned char Validate_Date( unsigned char day, unsigned char month, unsigned short year )
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
            scanf("%u", &day);
            if(month == 2 && (year % 4) == 0)
            {
                if(day >= 1 && day <=29)
                {
                    return 1;
                }
                else{ return 0; }
            }
            else if(month == 2 && (year % 4) != 0)
            {
                if(day >= 1 && day <=28)
                {
                    return 1;
                }
                else{ return 0; }
            }
            else if(day >= 1 && day <=31)
            {
                return 1;
            }
            else{ return 0; }
        }
        else{ return 0; }
    }
    else{ return 0; }
}