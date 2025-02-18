/*
Modify the function created in Exercise 4 to form the square out of whatever character is contained in the character parameter fillCharacter.
*/

#include <stdio.h>

int squarefigure(int side, char fillCharacter);

int main( void )
{
    int side;
    char fillCharacter;

    printf("Enter side of square: ");
    scanf("%d", &side);
    printf("Enter character to fill square: ");
    scanf(" %c", &fillCharacter);

    squarefigure(side, fillCharacter);

    return 0;
}

int squarefigure(int side, char fillCharacter)
{
    for(int i = 1; i <= side; i++)
    {
        for(int j = 1; j <= side; j++)
        {
            printf("%c",fillCharacter);
        }
        printf("\n");
    }
}