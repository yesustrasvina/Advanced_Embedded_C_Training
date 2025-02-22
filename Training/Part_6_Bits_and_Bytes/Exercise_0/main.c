#include <stdio.h>
#include "assert.h"


int main(void) {

    assert(ShiftBitLeft( 0xff, 4 ) == 0xf0 );
    assert(ShiftBitLeft( 0x01, 1 ) == 0x02 );

    assert( ShiftBitRight( 0xff, 4 ) == 0x0f );
    assert( ShiftBitRight( 0x04, 2 ) == 0x01 );

    assert( SetBitMask ( 0x01, 0x0A) == 0x0B );
    assert( SetBitMask ( 0xFF, 0x00) == 0xFF );

    assert( ClearBitMask ( 0xFF, 0x0F ) == 0xF0 );
    assert( ClearBitMask ( 0xFF, 0x01 ) == 0xFE );

    assert( ToggleBitMask ( 0xFF, 0xF0 ) == 0x0F);
    assert( ToggleBitMask ( 0xAA, 0xFF ) == 0x55);

    assert( SetBit ( 0x00, 4 ) == 0x10);
    assert( SetBit ( 0x00, 0 ) == 0x01);

    assert( ClearBit ( 0xFF, 0 ) == 0xFE);
    assert( ClearBit ( 0xFF, 7 ) == 0x7F);

    assert( ToggleBit ( 0xFF, 0) == 0xFE);
    assert( ToggleBit ( 0xFF, 4) == 0xEF);

    assert( GetBit ( 0xFF, 5 ) == 1);
    assert( GetBit ( 0xAA, 3 ) == 1);
    assert( GetBit ( 0xAA, 4 ) == 0);

    printf("All test passed\n");


    return 0;
}


