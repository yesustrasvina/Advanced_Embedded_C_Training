/* Packing messages into a specific format */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

void CanTp_SingleFrameTx( uint8_t *data, uint8_t size );

int main( void )
{
    uint8_t array[8] =    {2,3,4,5,0,0,0,0};
    uint8_t expected[8] = {4,2,3,4,5,0,0,0};
    CanTp_SingleFrameTx( array, 4 ); 

    assert(memcmp(array,expected,sizeof(expected)) == 0);
    printf("Test passed\n");

    return 0;
}

void CanTp_SingleFrameTx( uint8_t *data, uint8_t size )
{ 
    for(unsigned char i = 7; i > 0; i--)
    {
        *(data + i) = *(data + i - 1); 
    }
    *data = size;
}
