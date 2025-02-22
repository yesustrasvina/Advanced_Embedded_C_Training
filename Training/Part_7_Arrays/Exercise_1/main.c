/* Write a program C program to count Array elements made of char variables by using sizeof() operator. The try with and array made of short kind of elements  */

#include <stdio.h>

int main ( void )
{
    char array[] = "Hola";

    printf("The size of the array is: %lu \n",sizeof(array)); //It prints 5 cause it is automatically null-terminated. H o l a \0

    char array1[] = {'H','o','l','a'};

    printf("The size of the array is: %lu \n",sizeof(array1)); //Now it prints 4

    char array2[4] = "Hola";

    printf("The size of the array is: %lu \n",sizeof(array2)); //It prints 4

    return 0;
}