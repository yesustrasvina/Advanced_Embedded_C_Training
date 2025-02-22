#include <stdio.h>

//this is a array notation
/*void load( unsigned char *array, unsigned char size )
{
    for( int i=0 ; i<size ; i++ )
    {
        array[i] = 0xAA;
    }
}*/

unsigned  char array[] = {"Yesus"};
//this is a pointer notation
void load( unsigned char *array, unsigned char size )
{
    for( int i=0 ; i<size ; i++ )
    {
        *(array + i) = 0xAA;
        printf("%p\n",*(array+i));
    }
}

int main( void )
{
    load(array,5);
    return 0;
}