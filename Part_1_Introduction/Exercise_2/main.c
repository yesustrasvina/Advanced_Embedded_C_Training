/*
    Write a program that prints the numbers 1 to 4 on the same line. Write the program using the following methods. 

    Using one printf statement with no conversion specifiers.

    Using one printf statement with four conversion specifiers.

    Using four printf statements.
*/

#include <stdio.h>

int main ( void )
{
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;

    printf("1 2 3 4\n");

    printf( "%d %d %d %d\n",n1,n2,n3,n4);

    printf("1 ");
    printf("2 ");
    printf("3 ");
    printf("4 \n");
    

    return 0;
}