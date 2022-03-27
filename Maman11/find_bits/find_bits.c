/*

This program is question 2 of Mamam11 in the course "Maabada Betihnut maarahot"


*/

#include "functions.h"

int main(){

    unsigned long x = 0;
    unsigned long y = 0;

    welcomeMessage();
    x = getInput();

    printf("You have entered: %lu\nPlease enter the second number: (y): ", x);
    y = getInput();


   
    printf("You have entered: %lu\nThere are %d turned on bits in the two numbers.\n", y, get_turned_on_bits(x, y));
    return 0;
}



