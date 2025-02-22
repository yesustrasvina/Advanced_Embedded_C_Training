/* Write a C program to calculate median of an array.
In this C program, we are going to learn how to find the median of an array?
Here, we are reading N elements and finding their median element. */
  
#include <stdio.h>

int main ( void )
{
    unsigned char array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned char begin = 0, end = ( (sizeof(array) / sizeof(array[0])) - 1 );

    while( begin < end )
    {
        begin++;
        end--;
    }

    unsigned char lenght = sizeof(array) / sizeof(array[0]);

        if((lenght % 2) == 0 ) //Two number in middle of array, median is average
        {
            float average = (float) ((array[end] + array[end + 1]) / 2.0); //Explicit cast to float
            printf("Median of array is: %.2f\n", average);
           
        }
        else //Just one number in middle of array, print that number
        {
             printf("Median of array is: %hhu\n", array[end]);
        }
        

    return 0;
}
