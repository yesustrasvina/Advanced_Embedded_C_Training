#include "assert.h"

void printb(unsigned char byte)
{
        printf("0b"); //Binary prefix

        // Iterate through each bit (from most significant to least significant)
        for (int i = 7; i >= 0; i--) 
        {
            // Check if the i-th bit is set
            if ( byte & (1 << i) )   
            {
                printf("1");
            } 
            else 
            {
            printf("0");
            }
        }
        printf("\n");
}

unsigned char ShiftBitRight ( unsigned char byte, unsigned char shift )
{
     byte = ( byte >> shift );
     return byte;
}

unsigned char ShiftBitLeft( unsigned char byte, unsigned char shift )
{
     byte = ( byte << shift );
     return byte;
}

unsigned char SetBitMask( unsigned char byte, unsigned char mask )
{
    byte |= mask;
    return byte;
}

unsigned char ClearBitMask( unsigned char byte, unsigned char mask )
{
    byte &= ~( mask );
    return byte;
}

unsigned char ToggleBitMask( unsigned char byte, unsigned char mask )
{
    byte ^= ( mask );
    return byte;
}

unsigned char SetBit( unsigned char byte, unsigned char bit )
{
    byte |= (1 << bit);
    return byte;
}

unsigned char ClearBit( unsigned char byte, unsigned char bit )
{
    byte &= ~(1 << bit );
    return byte;
}

unsigned char ToggleBit( unsigned char byte, unsigned char bit )
{
    byte ^= ( 1 << bit );
    return byte;
}

unsigned char GetBit( unsigned char byte, unsigned char bit )
{
    byte &= ( 1 << bit );
    if( byte )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}