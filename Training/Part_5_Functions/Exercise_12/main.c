/*
Write a C program that plays the game of “guess the number” as follows:
Your program chooses the number to be guessed by selecting an integer at random in the range 1 to 1000. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void guessNumber(void);
int try;
char yesorno;

int main ( void )
{
    
    guessNumber();

    return 0;
}

void guessNumber( void )
{
    srand(time(NULL)); //Initialization
    int randomNumber = rand() % 1000;
    
    printf("I have a number between 1 and 1000. \nCan you guess my number? \nPlease type your first guess.\n");
    scanf("%d", &try);

    if(try != randomNumber)
    {
        do
        {
            printf("Incorrect number. \nWould you like to play again ( y or n)\n");
            scanf(" %c", &yesorno);
            if( try < randomNumber )
            {
                printf("Too low. Try again\n");
                printf("Enter your guess: ");
                scanf("%d", &try);
            }
            else if( try > randomNumber )
            {
                printf("Too high. Try again\n");
                printf("Enter your guess: ");
                scanf("%d", &try);
            }
            else if(try == randomNumber)
            {
                printf("Excellent! You guessed the number!\n");
            }
        }while(yesorno == 'y');
        if(yesorno == 'n')
        printf("Game over\n");
        
    }
    else if(try == randomNumber)
    {
        printf("Excellent! You guessed the number!\n");
    }
}
