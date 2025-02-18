/* Write a  C program to check prime numbers in an array. In this C program, we are going to learn to check prime numbers in an array.
 We will declare an array with some prime and non prime numbers, and then print the elements with “prime” and “Not prime” message. */
 
 #include <stdio.h>
 #include <math.h>

 unsigned char isPrime( unsigned char number);

 int main ( void )
 {
    unsigned char array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(unsigned char i = 0; i < sizeof(array); i++ )
    {
        if(isPrime(array[i])) //if return 1
        {
            printf("%hhu prime\n", array[i]);
            
        }
        else //if return 0
        {
            printf("%hhu not prime\n", array[i]); 
        }
       
    }
        

    return 0;
 }

 unsigned char isPrime(unsigned char number)
 {
    if(number == 0 || number == 1)  // 0 and 1 are not prime
    {
        return 0;  // Not prime
    }

    for(unsigned char i = 2; i <= sqrt(number); i++) // Loop from 2 to sqrt(number) example sqrt(36) is 6, if 
    {
        if(number % i == 0)  // If divisible by any i, it's not prime
        {
            return 0;  // Not prime
        }
    }
    return 1;  // If no divisors were found, it's prime
 }