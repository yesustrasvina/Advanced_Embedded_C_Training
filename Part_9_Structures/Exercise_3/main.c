/* Un-Packing bytes to serialize messages

Made a function that takes an structure with the elements below and place them byte by byte into and array made of 7 bytes, information shall 
be place in the following order: (Where word0 is the less significant byte of word element and word3 is the most significant byte, same with hword0 and hword1).

byte0 | byte1 | byte2 | byte3 | byte4 | byte5  | byte6 

word0 | word1  | word2 | word3  | byte     | hword0 | hword1 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct StructPack
{
    unsigned long word;
    unsigned char byte;
    unsigned short hword;
};

void UnpackingBytes( struct StructPack *message, unsigned char *array);

int main( void )
{
    unsigned char array[7] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77};
    struct StructPack word;
    UnpackingBytes(&word,array);
    
        printf("%08X %02X %04X", word.word, word.byte, word.hword);
    

    return 0;
}

void UnpackingBytes( struct StructPack *message, unsigned char *array)
{
    message->word = (array[0] << 0 | array[1] << 8 | array[2] << 16 | array[3] << 24);
    message->byte = array[4];
    message->hword = (array[5] << 0 | array[6] << 8);
}