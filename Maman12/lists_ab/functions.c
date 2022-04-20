

#include "functions.h"
/*
This function is used to welcome the user when they run the program

*/
void printWelcomeMessage(){
    printf("Hello!\nWelcome to question 1 of Maman12!\nPlease enter a text, and press CTRL-D in linux or CTRL-Z in windows  when you finish writing!\n");
}

/*
This function is used to take the characters from the user
The function does it by splitting the inputs into blocks, and each time the block ends, it will allocate more memory
@param letters the pointer to the place we want to take the input to
@return how many letters has been given

*/
int getInput(char** letters){

    int length = 0;
    int currentBlockLength = 1;
    char currChar;
    while((currChar = getchar()) != EOF){
        *(*letters + length) = currChar;
        if(currentBlockLength >= MEMORY_BLOCK){
            *letters = (char*)realloc(*letters, (length  + MEMORY_BLOCK) * sizeof(char));
            currentBlockLength= 0;
        }

        currentBlockLength++;
        length++;
    }
    
    return length;

}

/*
This function is used to count how many alphanumeric characters are there in an array of char
@param letters the pointer to the place where the characters are stored
@oaram length how many ketters are there
@return how many letters hare alphanumeric

*/

int countAlphaNumericCharacters(char* letters, int length){
    int i = 0;
    int counter = 0;
    for(i = 0; i < length; i++){
        if(isalnum(*(letters + i))){
            counter++;
        }
    }
    return counter;
}



/*
This function is used to print the result to the user, at the end of the program
@param letters the pointer to the place where the characters are stored
@oaram length how many ketters are there
@return none 

*/
void printAlphaNumericSum(char* letters, int length){
    printf("\nGreat!\nYou have typed %d characters in total!\n%d of them are alphanumeric characters!\n", length, countAlphaNumericCharacters(letters, length));
}


/*
This function is used to print the characters splited into lines
@param text the pointer to the place where the characters are stored
@oaram length how many ketters are there
@return none

*/
void printInPrettyFormat(char* text, int length){
    
    int i = 0;
    printf("\nThe input in a pretty format: \n");
    for(i = 0; i < length; i++){
        if(i % LINE_LENGTH == 0){
            printf("\n");
        }
        printf("%c", *(text + i));
        
    }

}
