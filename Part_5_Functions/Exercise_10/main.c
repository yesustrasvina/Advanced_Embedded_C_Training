/*
 Write a function to determine if the year is a leap year or not, return 1 if leap otherwise return 0
*/

#include <stdio.h>

unsigned char Validate_LeapYear( unsigned short year );

int main( void )
{
    unsigned short year;

    

    if(Validate_LeapYear(year))
    {
        printf("Is a leap year\n");
    }
    else{ printf("Is not a leap year\n"); }
    return 0;
}

unsigned char Validate_LeapYear( unsigned short year )
{
    printf("Enter year: ");
    scanf("%hu", &year);

    if(( year % 4) == 0 )
    return 1;
    else{ return 0; }
}