/* Write a C program to find occurrence of an element in one dimensional array */

#include <stdio.h>

int main ( void )
{
    unsigned char array[] = {1, 2, 3, 4, 2, 5, 2, 6};
    unsigned char ocurrence = 2, counter = 0;

    for(unsigned char i = 0; i < sizeof(array); i++)
    {
        if(array[i] == ocurrence)
        {
            counter++;
        }
    }
    printf("Number %hhu appears %hhu times in array\n", ocurrence, counter);

    return 0;
}