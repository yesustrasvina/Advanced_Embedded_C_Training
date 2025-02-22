/*  Write a program that sums a sequence of integers. Assume that the first integer read with scanf specifies the number of values remaining to be entered.
    Your program should read only one value each time scanf is executed. A typical input sequence might be 5 100 200 300 400 500
    where the 5 indicates that the subsequent five values are to be summed */

#include <stdio.h>

int main( void )
{
    unsigned short numsToSum = 0, n = 0, res = 0;

    printf("Enter the total of numbers to sum: ");
    scanf("%hu", &numsToSum);
    for(unsigned short i = 0; i < numsToSum; i++)
    {
        printf("Enter %hu number: ", i + 1);
        scanf("%hu",&n);
        res += n;
    }
    printf("Result of sum is: %d\n",res);

    return 0;
}