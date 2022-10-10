#include <stdio.h>

#define PIZZACOST 1.5


int main(){

    float costoPizzas;
    int numberOfSlices =3;

    costoPizzas = PIZZACOST * numberOfSlices;
    printf("Total bill is%f",costoPizzas);
}