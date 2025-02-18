/* Write  C program to count total number of elements divisible by a specific number in an array */

#include <stdio.h>

int main( void )
{
    unsigned char array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char divisor = 2, counter = 0;

    for(unsigned char i = 0; i < sizeof(array); i++)
    {
        if((array[i] % divisor) == 0)
        {
            counter++;
        }
    }
    printf("%hhu numbers in the array are divisibles by %hhu\n",counter,divisor);

    
    return 0;
}