/*  A function that copies an array to another array */

#include <stdio.h>
#include <string.h>
#include <assert.h>

void arrayCopy( unsigned char *arrayA, unsigned char *arrayB, unsigned char size );

unsigned char arrayA[] = { 1, 2, 3, 4, 5 };
unsigned char arrayB[] = { 5, 4, 3, 2, 1 };

int main ( void )
{
    
    unsigned char size = sizeof(arrayA);

    arrayCopy(arrayA,arrayB,size);

    assert( memcmp( arrayA, arrayB, 5 ) == 0 );
     printf("Test passed\n");

    return 0;
}

void arrayCopy( unsigned char *arrayA, unsigned char *arrayB, unsigned char size )
{
    for( int i=0 ; i<size ; i++ )
    {
        *(arrayA + i) = *(arrayB + i); // Copy arrayB[i] value to arrayA[i]
        
    }
    //memcpy(arrayA, arrayB, size); // Copy to arrayA what arrayB have
}

  