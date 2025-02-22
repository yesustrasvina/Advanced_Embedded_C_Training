/*  Function to convert date to a string representation */

#include <stdio.h>
#include <assert.h>
#include <string.h>

void DateString( char *string, unsigned char month, unsigned char day, unsigned short year, unsigned char weekday );
char string[30];
unsigned char month, day, weekday;
unsigned short year;

int main( void )
{

    printf("Enter month (1- 12): ");
    scanf("%hhu", &month);
    printf("Enter day: ");
    scanf("%hhu", &day);
    printf("Enter year: ");
    scanf("%hu", &year);
    printf("Enter weekday (1 Monday - 7 Sunday): ");
    scanf("%hhu", &weekday);

    DateString(string, month, day, year, weekday);
    printf("%s",string);

    assert(strcmp(string, "Aug 31, 2000 We\n") == 0); // strcmp() returns 0 if the strings are equal
    printf("Test passed\n");

    return 0;
}

void DateString( char *string, unsigned char month, unsigned char day, unsigned short year, unsigned char weekday )
{
    char *weekdayname[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"}; // Array of pointers of type char. Each pointer points to string(sequence of characters with \0 termination)
    char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; //monthnames[0] points to the string "Jan"

    sprintf(string, "%s %02hhu, %hu %s\n",monthnames[month - 1], day, year, weekdayname[weekday - 1]);
    
}