#include <stdlib.h>
#include <stdio.h>

typedef struct Person
{
    int age;
    char *name;
} Person;

int main(int argc, char *argv[])
{

    // 1. Dangling pointers
    Person *person1 = (Person *)malloc(sizeof(Person));
    person1 = NULL;

    // 2. DOuble frees
    Person *person2 = (Person *)malloc(sizeof(Person));
    free(person2);
    free(person2);

    // 3. Forgetting to use sizeof
    int *int_ptr = (int *)malloc(2);
    free(int_ptr);

    // 4. NULL pointer rertuirned from malloc, calloc or realoc
    char *name = (char *)malloc(100000000);
    *name = 'A'; // We could be deferencing an invalid pointer here

    return 0;
}