/* Function to get the largest number in a given array 
The function must return the highest value number in an array. */

#include <stdio.h>
#include <assert.h>

unsigned short largest( unsigned short *array, unsigned char size );
unsigned short array[] = { 1, 2, 3, 4, 5 };
unsigned short size = sizeof(array) / sizeof(array[0]), biggest = 0;

int main ( void )
{
    largest(array, size);

    assert(largest(array,size) == 5);
    printf("Test passed\n");

    return 0;
}

unsigned short largest( unsigned short *array, unsigned char size )
{
    for(unsigned short i = 0; i < size; i++)
    {
        if(*(array + i) > biggest)
        {
            biggest = *(array + i);
        }
    }
    return biggest;
}