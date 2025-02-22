/* Write a program that asks the user to enter two numbers, obtains them from the user, and prints their sum, product, difference, quotient, and remainder. */

#include <stdio.h>

int n1, n2, sum, product, difference, quotient,rem;

int main( void )
{
    
    printf("Enter first integer: ");
    scanf("%d",&n1);
    printf("Enter second integer: ");
    scanf("%d",&n2);
    printf("First number = %d second number = %d\n",n1,n2);

    sum =  n1 + n2;
    printf("Sum = %d\n", sum);

    product = n1 * n2;
    printf("Product = %d\n", product);

    difference = n1 - n2;
    printf("Difference = %d \n",difference);

    if(n2 != 0)
    {
    quotient = n1 / n2;
    printf("Quotient = %d\n", quotient);
    }
    else
    {
        printf("Can not divide / 0\n");
    }

    rem = n1 % n2;
    printf("Remainder = %d\n",rem);

    return 0;
}
