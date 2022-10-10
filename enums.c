#include <stdio.h>
#define freq =1000000;

enum weekDays{
     club=0,
     diamonds =5,
     hearts=10,
     spades=15
     
     }card;

int main(){

    card = spades;
    

    // enum weekDays today;
    // today = Saturday;

    printf("Crad power %d", sizeof(card));
   return 0;
}