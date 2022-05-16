
#include "input.h"

void getInput(char buffer[MAX_INPUT_LEN]){

    if(fgets(buffer, MAX_INPUT_LEN, stdin) == NULL){
        printf("Couldn't read input!\n");
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    
   
}



void getCommand(char input[MAX_INPUT_LEN], char command[MAX_ARGUMENT_LENGTH]){
    
    int i = 0;
    char currChar;
    for(i = 0; (currChar = *(input + i)) != SPACE && currChar != TAB && i < strlen(input) ; i++){
       
        command[i] = currChar;
    }
    command[i] = '\0';
    substring(input, i + 1);
}


void removeSpacesAndTabs(char* input){
    int i = 0;

    for(i = 0;  (input[i] == ' ' || input[i] == '\t') && i < strlen(input) ; i++);
    substring(input, i);



}



void substring(char* string, int length){
    int i = 0;
    int j = length;
    for(i = 0; j <= strlen(string); i++){
        string[i] = string[j];
        j++;
    }

    string[j] = '\0';
}

int is_paramater_number(char* parameter){
    int flag = 1;
    int i = 0;
    for(i = 0; *(parameter + i) != '\0'; i++){
        if(('9' < *(parameter + i) || *(parameter + i) < '0') && *(parameter + i) != '.' && *(parameter + i) != '-' && *(parameter + i) != '+') flag = 0;
    }
    return flag;
}



int foundEOF(char* input){
    int i = 0;
    for(;i < strlen(input); i++){
        if(input[i] == EOF) return 1;
    }
    return 0;
}



