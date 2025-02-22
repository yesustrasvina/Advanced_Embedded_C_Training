/*  Drivers are concerned with the mileage obtained by their automobiles. One driver has kept track of several tankfuls of gasoline by recording miles driven
    and gallons used for each tankful. Develop a program that will input the miles driven and gallons used for each thankful.
    The program should calculate and display the miles per gallon obtained for each tankful. After processing all input information,
    the program should calculate and print the combined miles per gallon obtained for all tankfuls. */

#include <stdio.h>
#include <stdint.h>

float milesPerGallon ( float gallons, float miles);

int main( void )
{
    uint8_t counter = 0;
    float gallons = 0, miles = 0;
    double totalAvg = 0;

    while (gallons != -1)
    {
        printf("Enter the gallons used (-1 to end): ");
        scanf("%f", &gallons);
        if(gallons == -1)
        {
            totalAvg = totalAvg / (double)counter;
            printf("The overall average miles / gallon was: %f\n",totalAvg);
            return 0;
        }      
        printf("Enter the miles driven: ");
        scanf("%f", &miles);
        printf("The miles / gallon for this tank was: %f\n", milesPerGallon(gallons,miles));
        counter++;
        totalAvg += milesPerGallon(gallons,miles);
    }
    return 0;
}

float milesPerGallon ( float gallons, float miles)
{
    float avg = miles / gallons;
    return avg;
}