#include <stdio.h>

int main(){

    float var1=5.1;
    float *p =&var1;
    printf("%f \n",p);
    printf("%f", *p);
}