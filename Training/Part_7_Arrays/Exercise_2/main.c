/*  Write a C program to swap first element with last, second to second last and so on (reversing elements).
 like, first element with last, second element with second last and so on... i.e. reversing the array elements */

 #include <stdio.h>

 int main( void )
 {
    unsigned char array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    unsigned char begin = 0, end = ( sizeof( array ) -1);

    //Print array before swap
    for(unsigned char i = 0; i <= sizeof( array ) - 1; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    
    while( begin < end )
    {
        unsigned char temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        begin++;
        end--;
    }


    //Print array after swap
    for(unsigned char i = 0; i <= sizeof( array ) - 1; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");


    return 0;
 }