/*Packing bytes from a serial message

Made a function that takes an array made of 11 bytes and place that information into a defined structured, information shall be place in the following order:
(Where word0 is the less significant byte of word element and word3 is the most significant byte, same with hword0 and hword1).

<StructPack>.word1  = byte0, byte1, byte2, byte3

<StructPack>.byte  = byte4

<StructPack>.hword  = byte5, byte6

<StructPack>.word2 = byte7, byte8, byte9, byte10  */

#include <stdio.h>

struct StructPack
    {
        unsigned long word1;
        unsigned long word2;
        unsigned char byte;
        unsigned short hword;
    };

void PackingBytes( unsigned char *array, struct StructPack *message);

int main( void )
{
    
    struct StructPack bytestosend = {0x11223344, 0x88990011, 0x55, 0x6677};

    unsigned char array[11];

    PackingBytes(array , &bytestosend);

    for(unsigned char i = 0; i < 11; i++)
    {
        printf("%02X",array[i]);
    }

    return 0;
}

void PackingBytes( unsigned char *array, struct StructPack *message)
{
    array[0] = (message->word1 >> 0) & 0xFF;
    array[1] = (message->word1 >> 8) & 0xFF;
    array[2] = (message->word1 >> 16) & 0xFF;
    array[3] = (message->word1 >> 24) & 0xFF;
    array[4] =  message->byte;
    array[5] = (message->hword >> 0) & 0xFF;
    array[6] = (message->hword >> 8) & 0xFF;
    array[7] = (message->word2 >> 0) & 0xFF;
    array[8] = (message->word2 >> 8) & 0xFF;
    array[9] = (message->word2 >> 16) & 0xFF;
    array[10] = (message->word2 >> 24) & 0xFF;
}