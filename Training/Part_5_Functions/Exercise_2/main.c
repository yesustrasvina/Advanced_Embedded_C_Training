/*
Write a function multiple that determines for a pair of integers whether the second integer is a multiple of the first.
The function should take two integer arguments and return 1 (true)
if the second is a multiple of the first, and 0 (false) otherwise.
Use this function in a program that inputs a series of pairs of integers.
*/

#include <stdio.h>

int n1, n2;
int ismultiple();

int main( void )
{

    if(ismultiple())
    printf("%d is multiple of %d\n", n1, n2);
    
    else
    printf("%d is not multiple of %d\n", n1, n2);

    return 0;
}

int ismultiple()
{
    printf("Enter first number: ");
    scanf("%d",&n1);
    printf("Enter second number: ");
    scanf("%d",&n2);
    if(n1 % n2 == 0)
    {
        return 1;
    }
    else{ return 0; }
}