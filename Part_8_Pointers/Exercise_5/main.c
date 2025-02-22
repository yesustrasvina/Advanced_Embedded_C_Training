/* Function to sort an array of a given size */

#include <stdio.h>
#include <assert.h>

void sortArray( unsigned short *array, unsigned char size );
unsigned short array[] = {1,3,5,4,2};
unsigned char size = sizeof(array) / sizeof(array[1]);
unsigned char temp = 0;
unsigned short expected[] = {1, 2, 3, 4, 5};

int main ( void )
{
    sortArray(array,size);

    for (unsigned char i = 0; i < size; i++)
    {
        assert(*(array + i) == *(expected + i)); // Check if sorted correctly
    }

    printf("Test passed\n");

    return 0;
}

void sortArray( unsigned short *array, unsigned char size )
{
    for(unsigned char i = 0; i < size - 1; i++) // After each pass, the largest unsorted element moves to its correct position.
    {
        for(unsigned char j = 0; j < size - 1; j++) // It swaps elements if they are out of order 
        {
            if(*(array + j) > *(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
        
    }
}