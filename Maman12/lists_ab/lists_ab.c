

/*
This program is question 1 of Mamam12 in the course "Maabada Betihnut maarahot"
*/
#include "lists_ab.h"
#include "functions.c"


int main(){


    char* letters = (char*)calloc(MEMORY_BLOCK, sizeof(char));
    int textLength = 0;

    printWelcomeMessage();
    textLength = getInput(letters);
    printInPrettyFormat(letters, textLength);

    printAlphaNumericSum(letters, textLength);
    return 0;
}


