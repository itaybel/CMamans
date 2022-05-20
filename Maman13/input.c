
#include "input.h"

/*
This function gets input from the user and stores in the memory
@return a pointer to the allocated memory
*/
char* getInput(){

    char* buffer = (char*)malloc(sizeof(char) * MEMORY_BLOCK);
    int length = 0;
    int currentBlockLength = 1;
    char currChar;
    while((currChar = getchar()) != '\n' && currChar != EOF){
        *(buffer + length) = currChar;
        if(currentBlockLength >= MEMORY_BLOCK){
            buffer = (char*)realloc(buffer, (length  + MEMORY_BLOCK) * sizeof(char));
            currentBlockLength= 0;
        }

        currentBlockLength++;
        length++;
    }

    buffer[length] = '\0';
    
    return buffer;
   
}


/*
This function gets a string containing the input from the user, and extracts the command from it
@param input: the input, that the user has written
@return a pointer to the allocated memory
*/
char* getCommand(char* input){
    
    char* buffer = (char*)malloc(sizeof(char) * MEMORY_BLOCK);
    int i = 0;
    int currentBlockLength = 1;
    char currChar;

     for(i = 0; (currChar = *(input + i)) != SPACE && currChar != TAB && i < strlen(input) ; i++){
       
        *(buffer + i) = currChar;
        if(currentBlockLength >= MEMORY_BLOCK){
            buffer = (char*)realloc(buffer, (i  + MEMORY_BLOCK) * sizeof(char));
            currentBlockLength= 0;
        }

        currentBlockLength++;
     }
    buffer[i] = '\0';
    return buffer;

}

/*
This function gets a string containing the input from the user, and removes the spaces/tabs that are at the beginning
@param input: the input, that the user has written
@return none
*/
void removeSpacesAndTabs(char* input){
    int i = 0;

    for(i = 0;  (input[i] == ' ' || input[i] == '\t') && i < strlen(input) ; i++);
    substring(input, i);



}


/*
This function gets a string , and a number length, and removes the first length's chars from the string
@param string: a string to be changed
@param length: how much chars to remove
@return none
*/
void substring(char* string, int length){
    int i = 0;
    int j = length;
    for(i = 0; j <= strlen(string); i++){
        string[i] = string[j];
        j++;
    }

    string[j] = '\0';
}



/*
This function gets a string , and checks wether the string has valid chars of a double
@param parameter: the string to be checked
@return wether its valid or not
*/
int foundEOF(char* input){
    int i = 0;
    for(;i < strlen(input); i++){
        if(input[i] == EOF) return 1;
    }
    return 0;
}



