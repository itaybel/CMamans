

void printWelcomeMessage();
int getInput(char* input);
void printInPrettyFormat(char* text, int length);
int countAlphaNumericCharacters(char* letters, int length);
int isAlphaNumeric(char letter);
void printAlphaNumericSum(char* letters, int length);


/*
This function is used to welcome the user when they run the program

*/
void printWelcomeMessage(){
    printf("Hello!\nWelcome to question 1 of Maman12!\nPlease enter a text, and beware that you cant delete any charactars you have already written!\nIn order to finish the program use the key %c if you are running it directly, otherwise if the input is from a file, just run it.\n", END_KEY);
}

/*
This function is used to take the characters from the user
The function does it by splitting the inputs into blocks, and each time the block ends, it will allocate more memory
@param letters the pointer to the place we want to take the input to
@return how many letters has been given

*/
int getInput(char* letters){

    int length = 0;
    int currentBlockLength = 0;

    while(*(letters + length - 1) != EOF && *(letters + length - 1) != END_KEY){
        *(letters + length) = getch();

        if(currentBlockLength >= MEMORY_BLOCK){
            letters = (char*)realloc(letters, length + MEMORY_BLOCK * sizeof(char));
            currentBlockLength= 0;
        }
        
        putchar(*(letters + length));
        length++;
    }
    return length - 1;

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
        counter += isAlphaNumeric(*(letters + i)); 
    }
    return counter;
}

/*
This function is used to tell wheter a character is an alphanumeric character or not
@param letter the character we are currently checking

@return 1 if the character is alphanumeric, otherwise 0
*/
int isAlphaNumeric(char letter){
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || (letter >= '0' && letter <= '9');
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
    
    char* curr = text;
    int lettersInARow = 0;
    printf("\nThe input in a pretty format: \n");
    for(; curr < text + length - 1; curr++){
        if((lettersInARow >= LINE_LENGTH || *curr == '\n') && *curr == ' '){
            printf("\n");
            lettersInARow = 0;
        }else{
            printf("%c", *curr);
            lettersInARow++;
        }
    }

}
