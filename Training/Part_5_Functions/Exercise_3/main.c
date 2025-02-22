/*
Write a program that inputs a series of integers and passes them one at a time to function even,
which uses the remainder operator to determine if an integer is even.
The function should take an integer argument and return 1 if the integer is even and 0 otherwise.
*/

#include <stdio.h>

int n1,res;
int IsEven();

int main( void )
{
    printf("Enter number: ");
    scanf("%d", &n1);
    if(IsEven(n1))
    {
        printf("%d is even number\n",n1);
    }
    else{ printf("%d is not an even number\n",n1); }

    return 0;
}

int IsEven()
{
    if(n1 % 2 == 0)
    {
        return 1;
    }
    else{ return 0; }
}