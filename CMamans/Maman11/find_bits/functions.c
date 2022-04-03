
#include <stdio.h>

/*
This function is used to calculate how many turned bits are there for the two given numbers
The function does it by getting the new number after being & with the two numbers, then, we will iterate until its zero, just like how we transfer a base10 number to a binary number,
but this time, instead of saving the 'num % 2' at the side, we use it to check if we need to increment the varibale that stored all the ones
@param x the first number 
@param y the second number

*/
int get_turned_on_bits(unsigned long x, unsigned long y){

    int ones = 0;
    unsigned long after_and = x & y;

    while(after_and > 0){
        
        if(after_and % 2 == 1){  /*an explantion is provided in the functions.c file*/
            ones++;
        }
        after_and /= 2;
    }

    return ones;
}

/*
This function prints welcome message to the user
*/
void welcomeMessage(){
    printf("Hello!\nWelcome to the second question of Mamam11!\nPlease enter the first number: (x): ");
}


/*
This function takes an unsigned long from the user.
@return the input from the user
*/
int getInput(){
    unsigned long input = 0;
    scanf("%lu", &input);
    return input;
}