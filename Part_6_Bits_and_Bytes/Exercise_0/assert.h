#ifndef ASSERT_H
#include <stdio.h>
#include <assert.h>

/* Function that allows printing the binary format of an 8-bit variable. */
void printb(unsigned char byte);

/* Function that right rotates the bits of a variable. */
unsigned char ShiftBitRight ( unsigned char byte, unsigned char shift );

/* Function that left-rotates the bits of a variable. */
unsigned char ShiftBitLeft( unsigned char byte, unsigned char shift );

/* A function that sets the bits of a variable according to a given mask. */
unsigned char SetBitMask( unsigned char byte, unsigned char mask );

/* A function that clears the bits of a variable according to a given mask. */
unsigned char ClearBitMask( unsigned char byte, unsigned char mask );

/* Function that inverts the bits of a variable according to the mask. */
unsigned char ToggleBitMask( unsigned char byte, unsigned char mask );

/* Function to set a specific bit of a variable to one. */
unsigned char SetBit( unsigned char byte, unsigned char bit );

/* Function that allows setting a specific bit of a variable to zero. */
unsigned char ClearBit( unsigned char byte, unsigned char bit );

/* Function that allows inverting a specific bit of a variable. */
unsigned char ToggleBit( unsigned char byte, unsigned char bit );

/* Function that returns the value of a bit in a variable. */
unsigned char GetBit( unsigned char byte, unsigned char bit );

#endif