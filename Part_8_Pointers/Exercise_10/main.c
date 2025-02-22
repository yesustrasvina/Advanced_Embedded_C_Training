/* Unpacking messages from a specific format */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

uint8_t CanTp_SingleFrameRx( uint8_t *data, uint8_t *size );

int main( void )
{
    uint8_t array[8] = { 0x04, 0x02, 0x03, 0x04, 0x05, 0xAA, 0x00, 0xFF}; 
    uint8_t size;
    CanTp_SingleFrameRx( array, &size );

    
    uint8_t expected[8] = { 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x00, 0x00 };
    assert(memcmp(array,expected,sizeof(expected)) == 0); 
    printf("Test passed\n");

    return 0;
}

uint8_t CanTp_SingleFrameRx( uint8_t *data, uint8_t *size )
{    
    *size = data[0];

    for(uint8_t i = 0; i < *size; i++) //Shift values to left [0] to [3]
    {
        *(data + i) = *(data + i + 1);
    }

    for(uint8_t i = *size; i < 8; i++) //Clear values [4] to [7]
    {
        *(data + i) = 0x00;
    }

    return 1;
}