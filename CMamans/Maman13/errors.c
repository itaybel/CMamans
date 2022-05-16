#include "error.h"
int isExtraText(char* input){
    removeSpacesAndTabs(input);
    return input[0] == '\n' || input[0] == '\0';
}




