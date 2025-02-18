#include "buffer.h"

int main( void )
{
    test__AppBuffer_initBuffer__buffer_intialization();
    test__AppBuffer_writeData__writting_a_single_data();
    test__AppBuffer_writeData__filling_the_buffer();
    printf("All tests passed\n");

    unsigned char dato;
    unsigned char data;
    unsigned char arreglo[200];
    AppBuffer_Buffer CircBuffer;

    /* Inicializacion */
    CircBuffer.Buffer = arreglo;
    CircBuffer.Elements = 200U;
    AppBuffer_initBuffer( &CircBuffer );

    /* Writtting in the buffer */
    dato = 100;
    AppBuffer_writeData ( &CircBuffer, dato );
    dato = 120;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 200;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 201;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 202;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 255;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 254;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 253;
    AppBuffer_writeData( &CircBuffer, dato );
    dato = 125;
    AppBuffer_writeData( &CircBuffer, dato );

    /* Read all the messages */
    while( AppBuffer_isBufferEmpty( &CircBuffer ) == FALSE )
    {
        data = AppBuffer_readData( &CircBuffer );
        printf("Data read form the queue %hhu\n", data);
    }

    return 0;
}
