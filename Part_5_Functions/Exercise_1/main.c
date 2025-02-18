/*
Write a function integerPower(base, exponent) that returns the value of base exponent For example, integerPower( 3, 4 ) = 3 * 3 * 3 * 3.
 Assume that exponent is a positive, nonzerointeger, and base is an integer.
  Function integerPower should use for to control the calculation. Do not use any math library functions.
*/

#include <stdio.h>

int integerPower();
int base, exponent, res, temp;

int main( void )
{
    printf("Enter base: ");
    scanf("%d",&base);
    printf("Enter exponent: ");
    scanf("%d",&exponent);

    if(exponent != 0)
    integerPower(base,exponent);
    else
    printf("Exponent can't be 0\n");
    return 0;
}

int integerPower()
{
    res = base;
    for(int i = 1; i <= exponent; i++)
    {
        res = res * base;
        
        printf("res(%d) = %d \n",i,res);
    }
    printf("Result is: %d\n",res);
}