/* Function to convert time to a string representation plus a string */

#include <stdio.h>
#include <assert.h>

void AlarmString( char *string, unsigned char hours, unsigned char minutes );
char string[12] = {};
unsigned char size = sizeof(string) / sizeof(string[0]);

int main( void )
{
    unsigned char hours = 15, minutes = 55;
    AlarmString(string, hours, minutes);
    printf("%s\n",string);

    assert(string[0] == 'A' && string[1] == 'L' && string[2] == 'A' && string[3] == 'R' &&
           string[4] == 'M' && string[5] == '=' && string[6] == '1' && string[7] == '5' &&
           string[8] == ':' && string[9] == '5' && string[10] == '5' && string[11] == '\0'); // Expected output ALARM=15:55
    
    printf("Test passed\n");

    return 0;
}

void AlarmString( char *string, unsigned char hours, unsigned char minutes )
{
    string[0] = 'A';
    string[1] = 'L';
    string[2] = 'A';
    string[3] = 'R';
    string[4] = 'M';
    string[5] = '=';
    string[6] = '0' + hours / 10;
    string[7] = '0' + hours % 10;
    string[8] = ':';
    string[9] = '0' + minutes / 10;
    string[10] = '0' + minutes % 10;
    string[11] = '\0';
}
