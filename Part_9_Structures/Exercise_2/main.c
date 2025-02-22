/* write an expression that can be used to access the structure members in each of the following parts:

a) Member lastName of structure customerRecord.

b) Member lastName of the structure pointed to by customerPtr.

c) Member firstName of structure customerRecord.

d) Member firstName of the structure pointed to by customerPtr.

e) Member customerNumber of structure customerRecord.

f) Member customerNumber of the structure pointed to by customerPtr.

g) Member phoneNumber of member personal of structure customerRecord.

h) Member phoneNumber of member personal of the structure pointed to by customerPtr.

i) Member address of member personal of structure customerRecord.

j) Member address of member personal of the structure pointed to by customerPtr.

k) Member city of member personal of structure customerRecord.

l) Member city of member personal of the structure pointed to by customerPtr.

m) Member state of member personal of structure customerRecord.

n) Member state of member personal of the structure pointed to by customerPtr.

o) Member zipCode of member personal of structure customerRecord.

p) Member zipCode of member personal of the structure pointed to by customerPtr. */

#include <stdio.h>

struct customer
{
    char lastName[15];
    char firstName[15];
    int customerNumber;
    struct
    {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    }personal;
}customerRecord, *customerPtr;

customerPtr = &customerRecord;

int main( void )
{
    customerPtr->lastName; //Dereferebcing with -> cause customerPtr is a pointer to structure
    customerRecord.lastName; //Accesing with . cause customerRecord is a structure, not a pointer

    customerPtr->firstName;
    customerRecord.firstName;

    customerPtr->customerNumber;
    customerRecord.customerNumber;

    customerPtr->personal->phoneNumber;
    customerRecord.personal.phoneNumber;

    customerPtr->personal->address;
    customerRecord.personal.address;

    customerPtr->personal->city;
    customerRecord.personal.city;

    customerPtr->personal->state;
    customerRecord.personal.state;

    customerPtr->personal->zipCode;
    customerRecord.personal.zipCode;

    return 0;
}