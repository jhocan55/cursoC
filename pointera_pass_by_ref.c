#include <stdlib.h>
#include <stdio.h>

/**
 * Function declaration
*/
void print_int_by_reference(int* number_ptr);
void print_int_by_value(int number);
void malloc_int_dangerous(int* number_ptr);
void malloc_int_safe(int** number_ptr);

int main(int argc, char *argv[])
{
    //Give an example of passing an int via a pinter instead by a value
    int my_number = 10;

    print_int_by_value(my_number);
    print_int_by_reference(&my_number);

    printf("Theadddresses printed above should be different \n\n\n");

    int* number_ptr = &my_number;

    printf("'number_ptr' before malloc: %p\n",number_ptr);

    //1. Create function that takes in a pointer to an int, attemps to malloc memory for it and return the pointer -
    //this will not work (memory leak will occur... becasue the pointer passed in points to memory on the stack)
    malloc_int_dangerous(number_ptr);

    printf("Original 'number_ptr' adrdress after dangerous malloc %p\n", number_ptr);
    printf("The above address for 'number_ptr' does not change\n");

    //2. Create a function that takes in a double pointer to an int and malloc memory to the dereferenced double pointer
    malloc_int_safe(&number_ptr); //Pass the address of the 'number_ptr' pointer

    printf("'number_ptr' address after safe malloc: %p", number_ptr);

    free(number_ptr);
    number_ptr=NULL;
    return 0;
    

   
}

void print_int_by_reference(int* number_ptr){
    printf("Printing Int =>> Address: %p | Value %d", number_ptr, *number_ptr);
}
void print_int_by_value(int number){
    printf("Printing Int =>> Address: %p | Value %d", &number, number);
}
void malloc_int_dangerous(int* number_ptr){
    number_ptr = (int*)malloc(sizeof(int));
    printf("[malloc_int_dangerous] =>>  'number_ptr' address after dangeroous malloc %p\n", number_ptr );
    printf("[malloc_int_dangerous] =>>  That address space marks a memory-leaked block\n\n");
    //'number_ptr' now goes out of scope and you have a memory leak
}

//This will work nicely and will not cause a memory leak as long as the caller of this function frees the memory
void malloc_int_safe(int** number_ptr){

    *number_ptr =(int*)malloc(sizeof(int));
}