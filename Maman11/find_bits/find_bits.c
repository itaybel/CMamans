/*

This program is question 2 of Mamam11 in the course "Maabada Betihnut maarahot"


*/


int main(){

    unsigned long x = 0;
    unsigned long y = 0;

    welcomeMessage();
    x = getInput();

    printf("Great!\nPlease enter the second number: (y): ");
    y = getInput();


   
    printf("There are %d turned on bits in the two numbers.\n", get_turned_on_bits(x, y));
    return 0;
}



