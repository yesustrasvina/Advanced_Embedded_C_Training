/* Function to compare two arrays return 0 if theyre equals and return 1 if theyre differents*/

#include <stdio.h>
#include <assert.h>

unsigned char arrayCompare( unsigned char *arrayA, unsigned char *arrayB, unsigned char size );

unsigned char arrayA[] = {1, 2, 3, 4, 5};
unsigned char arrayB[] = {1, 2, 3, 4, 5};
unsigned char size = sizeof(arrayA) / sizeof(arrayA[0]);

int main ( void )
{
    arrayCompare(arrayA,arrayB,size);

    assert(arrayCompare(arrayA, arrayB, size) == 0); // Check if arrays are equals
    printf("Test passed\n");
    return 0;
}

unsigned char arrayCompare( unsigned char *arrayA, unsigned char *arrayB, unsigned char size )
{
    for(unsigned char i = 0; i < size; i++)
    {
        if(*(arrayA + i) != *(arrayB + i))
        {
            return 1; //If we have 1 different value return 1
        }
    }
    return 0; //If all values are equals, return 0
}