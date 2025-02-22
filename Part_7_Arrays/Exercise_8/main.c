/* Use the string library to perform the following operations

Compare two arrays of memory

Copy one array content to another

Fill an array with a given value

Compare two strings

Get the string length

Concatenates two strings. */

#include <stdio.h>
#include <string.h>

int main ( void )
{
    unsigned char array[] = { "Yesus" };
    unsigned char array2[] = { "Embedded" };

    memcmp(array, array2, 5); // The memcmp() function compares two blocks of memory and returns an integer indicating which one is greater.

    memcpy(array, array2, sizeof(array)); //  memcpy()	Copies data from one block of memory to another. array must be equal or less size

    memset(array2, 0, sizeof(array2));  /* memset() is used to fill a block of memory with a particular value. 
                                         First address of memory to be filled, value to be filled, number of bytes to be filled */

    strcmp(array, array2);  // The strcmp() function compares two strings and returns an integer indicating which one is greater.

    strlen(array);  // The strlen() function returns the length of a string, which is the number of characters up to the first null terminating character.

    strcat(array, "HI"); // The strcat() function appends a copy of one string to the end of another.
}