/* Function to convert time to a string representation */

#include <stdio.h>
#include <assert.h>

void TimeString( char *string, unsigned char hours, unsigned char minutes, unsigned char seconds );
char string[9] = "00:00:00";
unsigned char hours = 15, minutes = 30, seconds = 00, size;
void printArray(char *array);
void askUser();


int main( void )
{
    // askUser();
    TimeString(string, hours, minutes, seconds);
    printArray(string);

    assert(string[0] == '1' && string[1] == '5' && string[2] == ':' && 
           string[3] == '3' && string[4] == '0' && string[5] == ':' && 
           string[6] == '0' && string[7] == '0' && string[8] == '\0');  // Expected result 15:30:00

    printf("Test passed\n");

    return 0;
}

void TimeString( char *string, unsigned char hours, unsigned char minutes, unsigned char seconds )
{
    // Manually format time with leading zeros and store in string
    string[0] = '0' + (hours / 10);  // First digit of hours 15 / 10 = 1
    string[1] = '0' + (hours % 10);  // Second digit of hours 15 % 10 = 5
    string[2] = ':';                 // Colon separator
    string[3] = '0' + (minutes / 10); // First digit of minutes 30 / 10 = 3
    string[4] = '0' + (minutes % 10); // Second digit of minutes 30 % 10 = 0
    string[5] = ':';                 // Colon separator
    string[6] = '0' + (seconds / 10); // First digit of seconds 0 / 10 = 0
    string[7] = '0' + (seconds % 10); // Second digit of seconds 0 % 10 = 0
    string[8] = '\0';                // Null terminator

    // sprintf(string,"%02hhu:%02hhu:%02hhu",hours,minutes,seconds);
}

void printArray(char *array)
{
    printf("%s\n",array);
}

void askUser()
{
    printf("You will enter hours (0 - 24), minutes (0 - 59) and seconds (0 - 59)\n");
    printf("Enter hours: ");
    scanf("%hhu",&hours);
    printf("Enter minutes: ");
    scanf("%hhu",&minutes);
    printf("Enter seconds: ");
    scanf("%hhu",&seconds);
}