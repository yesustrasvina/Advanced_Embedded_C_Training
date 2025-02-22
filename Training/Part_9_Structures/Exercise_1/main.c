/* Provide the definition for each of the following structures and unions:

Structure inventory containing character array partName[ 30 ], integer partNumber, floating point price, integer stock and integer reorder.

Union data containing char c, short s, long b, float f and double d.

A structure called address that contains character arrays streetAddress[ 25 ], city[ 20 ], state[ 3 ] and zipCode[ 6 ].

Structure student that contains arrays firstName[ 15 ] and lastName[ 15 ] and variable homeAddress of type struct address from part (c).

Structure test containing 16 bit fields with widths of 1 bit. The names of the bit fields are the letters a to p. */

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char partName[30];
    unsigned short partNumber;
    float price;
    unsigned char stock;
    unsigned char reorder;
}shopInventory;

union Test
{
    char c;
    short s;
    long b;
    float f;
    double d;
};

typedef struct
{
    unsigned char streetAddress[25];
    unsigned char city[20];
    unsigned char state[3];
    unsigned char zipCode[6];
}Address;

typedef struct
{
    unsigned char firstName[15];
    unsigned char lastName[15];
    Address homeAddress;
}student;

typedef struct 
{
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
    unsigned char i : 1;
    unsigned char j : 1;
    unsigned char k : 1;
    unsigned char l : 1;
    unsigned char m : 1;
    unsigned char n : 1;
    unsigned char o : 1;
    unsigned char p : 1;
}test;



int main( void )
{
    shopInventory part0;
    strcpy(part0.partName, "Module");
    part0.partNumber = 100;
    part0.price = 1350.67;
    part0.stock = 5;
    part0.reorder = 1;

    shopInventory part1 = { "Tire", 100, 1230.4,6,3};

    union Test firstUnion;
    firstUnion.c = 1;
    printf("Size of test structure: %hhu bytes\n",sizeof(test));
}
