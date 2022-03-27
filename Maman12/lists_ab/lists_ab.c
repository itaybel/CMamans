

/*
This program is question 1 of Mamam12 in the course "Maabada Betihnut maarahot"
*/
#include "functions.h"


int main(){


    char* letters = (char*)malloc(MEMORY_BLOCK *  sizeof(char));
    int textLength = 0;

    printWelcomeMessage();
    textLength = getInput(&letters);
    printInPrettyFormat(letters, textLength);

    printAlphaNumericSum(letters, textLength);

    free(letters);
    return 0;
}


    