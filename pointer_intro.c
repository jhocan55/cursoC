#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[])
{
    int my_number=10;

    //Declare a pointer
    int *my_ptr;

    //Getting the address of my_number using the "address operator -&"
    printf("Address of 'my_number': %p\n", &my_number);

    //Intilize a pointer using the "Address operator -&"
    my_ptr=&my_number;

    //Initilize a pointer using malloc
    char *name = (char*)malloc(8*sizeof(char));

    //Dereference a pointer to read a value at its address
    printf("Value of my number: %d\n", *my_ptr);

    int my_copied_number = *my_ptr;

    printf("Value of my copied number: %d\n", my_copied_number);

    //Dereference a pinter to assig a value to its address

    *my_ptr=20;
    printf("Value of my number after assigning a new value: %d\n",*my_ptr);
    free(name);
    return 0;
    
}