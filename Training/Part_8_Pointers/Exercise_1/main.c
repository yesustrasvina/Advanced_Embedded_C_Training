/* A function that calculates the average of the values in an array */

#include <stdio.h>
#include <assert.h>

float average( unsigned char *array, unsigned char size);

unsigned char array1[5] = { 9, 9, 10, 9, 9 };

float res = 0;

int main ( void )
{
    unsigned char size = sizeof(array1) / sizeof(array1[1]);

    res = average(array1,size);
    
    printf("Average of array is: %.1f\n",res);

    assert(res == 9.2f);

    printf("Test passed\n");

    return 0;
}

float average( unsigned char *array, unsigned char size)
{
    unsigned char counter = 0;
    for(int i = 0; i < size; i++)
    {
        counter += *(array + i);
    }
    return (float) counter / size;
}