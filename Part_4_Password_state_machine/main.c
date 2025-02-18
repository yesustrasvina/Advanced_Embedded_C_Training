/*
Design a program to read a password made of 3 numeric digits that prints the legend “Door Open“
if it was typed correctly, or “Error, try again“ if some number was type incorrect.
The program shall follow the state machine diagram below.
Notice there are transition with a condition this is interpreted as an if sentence and those transition in blank are not conditioned.
*/

#include <stdio.h>

enum
{
    ON,
    OFF,
    IDLE,
    FIRST_DIGIT,
    SECOND_DIGIT,
    THIRD_DIGIT,
    FOURTH_DIGIT,
    FIFHT_DIGIT,
    OPEN_DOOR1, // Password 1: 36579
    OPEN_DOOR2,  //Password 2: 36581
    ERROR
};

int main( void )
{
    int state = IDLE;
    int run = ON;
    int d1,d2,d3,d4,d5;
    
    while( run == ON )
    {
        switch( state )
        {
            case IDLE:
                //display welcome mesage
                printf("\nThis is a password state machine.\n Please enter digit per digit to open door 1 or door 2.\n Enter first digit: ");
                scanf("%d",&d1);
                state = FIRST_DIGIT;
            break;
    
            case FIRST_DIGIT:
                //read number and query if is correct
                if(d1==3)
                {
                    printf("Enter second digit: ");
                    scanf("%d",&d2);
                    state = SECOND_DIGIT;
                }
                else{ state = ERROR; }
            break;
    
            case SECOND_DIGIT:
                //read number and query if is correct
                if(d2==6)
                {
                    printf("Enter third digit: ");
                    scanf("%d",&d3);
                    state = THIRD_DIGIT;
                }
                else{ state = ERROR; }
            break;
    
            case THIRD_DIGIT:
                //read number and query if is correct
                if(d3==5)
                {
                    printf("Enter fourth digit: ");
                    scanf("%d",&d4);
                    state = FOURTH_DIGIT;
                }
                else{ state = ERROR; }
            break;

            case FOURTH_DIGIT:
                //read number and query if is correct
                if(d4 == 7)
                {
                    printf("Enter fifth digit: ");
                    scanf("%d",&d5);
                    state = FIFHT_DIGIT;
                }
                else if(d4 == 8)
                {
                    printf("Enter fifth digit: ");
                    scanf("%d",&d5);
                    state = FIFHT_DIGIT;
                }
                else{ state = ERROR; }
            break;

            case FIFHT_DIGIT:
                //read number and query if is correct
                if(d4 == 7 && d5 == 9)
                {
                    state = OPEN_DOOR1;
                }
                else if(d4 == 8 && d5 == 1)
                {
                    state = OPEN_DOOR2;
                }
                else{ state  = ERROR; };
            break;
    
            case OPEN_DOOR1:
                //display open door message
                printf("Congratulations, you opened door number 1.\n");
                //and end the program
                run = OFF;
            break;
            
            case OPEN_DOOR2:
                //display open door message
                printf("Congratulations, you opened door number 2.\n");
                //and end the program
                run = OFF;
            break;
    
            case ERROR:
                //display error message
                printf("Incorrect password. Try again.\n");
                state = IDLE;
            break;
    
            default:
            break;
        }
    }
}