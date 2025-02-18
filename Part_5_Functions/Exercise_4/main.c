/*
Write a function that displays a solid square of asterisks whose side is specified in the integer parameter side.
*/

#include <stdio.h>

void squarefigure(int side);



int main( void )
{
    int side;

    printf("Enter side of square: ");
    scanf("%d",&side);

    squarefigure(side);

    printf("\n");

    return 0;
}

void squarefigure(int side)
{
    for(int i = 1; i <= side; i++)
    {
        printf("\n");
        for(int j = 1; j <= side; j++)
        {
            printf("*");
        }
    }
    printf("\n");
}

