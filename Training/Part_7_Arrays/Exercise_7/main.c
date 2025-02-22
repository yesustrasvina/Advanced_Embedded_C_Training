/* Write a C program to replace all EVEN elements by 0 and Odd by 1 in One Dimensional Array.
 This program will read 10 elements of integer type using One Dimensional Array and replace all EVEN elements by 0 and ODD by 1. */

 #include <stdio.h>

 int main ( void )
 {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
    {
        if(array[i] % 2 == 0) // If is EVEN replace by 0
        {
            array[i] = 0;
        }
        else // If is ODD replace by 1
        {
            array[i] = 1;
        }
    }

    for(int i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
    {
        printf("[%d] element of array is %d\n",i, array[i]);
    }
    return 0;
 }