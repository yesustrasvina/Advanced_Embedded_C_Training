/*
Write a program that asks the user to enter two integers, obtains the numbers from the user,
 then prints the larger number followed by the words “is larger.”
  If the numbers are equal, print the message “These numbers are equal.” 
  Use only the single-selection form of the if statement you learned in this chapter.
*/

#include <stdio.h>

int main( void )
{
  int n1,n2;

  printf("Enter first integer: ");
  scanf("%d",&n1);
  printf("Enter second integer: ");
  scanf("%d",&n2);

  if(n1>n2)
  {
    printf("%d is larger\n",n1);
  }
  else if(n1<n2)
  {
    printf("%d is larger\n",n2);
  }
  else if(n1 == n2)
  {
    printf("These numbers are equal\n");
  }

  return 0;
}