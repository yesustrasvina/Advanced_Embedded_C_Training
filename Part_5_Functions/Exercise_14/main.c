/*
The greatest common divisor (GCD) of two integers is the largest integer that evenly divides each of the two numbers.
Write function gcd that returns the greatest common divisor of two integers.
*/

#include <stdio.h>

int getgcd(int n1, int n2);
int n1, n2, gcd;   

int main( void )
{
    

    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    getgcd(n1, n2);

    printf("Greatest common divisor of %d and %d is : %d\n", n1, n2, gcd);

    return 0;
}

int getgcd(int n1, int n2)
{
   for(int i = 1; i <= n1 && i <= n2; i++)
   {
    if( ( ( n1 % i ) == 0 ) && ( ( n2 % i ) == 0 ) )
    {
        gcd = i;
    }
   }
   return gcd;
}