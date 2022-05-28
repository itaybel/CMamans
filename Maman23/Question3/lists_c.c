#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int validArguments(int argc, char** argv);

int main(int argc, char** argv){

    if(validArguments(argc, argv)){
        textBlock* head = extractFileContent(argv[1]);
        printList(head);
        freeList(head);
        return 0;
    }
    return 1;
}

/*
This function check if the given main argumens are valid or not
@param argc,argv, the default main arguments
@return wether the arguments are valid, which means if the file could be opened successfully
*/
int validArguments(int argc, char** argv){
    FILE* file = NULL;
    if(argc != 2){
        printf("Invalid number of arguments!\nYou should be only specifing the file name!\n");
        return 0;
    }
    file = fopen(argv[1], "r");
    /* If it couldnt open the file*/
    if(file == NULL){
        printf("Cant open the file!\n");
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;

}
