#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define TEXT_BLOCK 5
#define MAX_LINE_LENGTH 20

typedef struct textBlock{
    char str[TEXT_BLOCK];
    struct textBlock* next;
} textBlock;

int validArguments(int argc, char** argv);
textBlock* createBlock();
textBlock* extractFileContent(char* file_name);
void printList(textBlock* head);
void freeList(textBlock* curr);

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
/*
This function creates and allocates memory for a textBlock struct
@param none
@return a pointer to the allocated memory
*/
textBlock* createBlock(){
    textBlock* newNode = (textBlock*)malloc(sizeof(textBlock));
    return newNode;
}
/*
This function reads the content of a file and inserts it to a linked list
@param file_name: the name of the file to be read
@return head to the created linked list, which contains all the content
*/
textBlock* extractFileContent(char* file_name){
    FILE* file = fopen(file_name, "r");
    char ch;
    int currBlockLength = 0;
    textBlock* head = createBlock();
    textBlock* curr = head;

     if(file == NULL){
        printf("Cant open the file!\n");
        fclose(file);
        return 0;
    }

    while((ch = fgetc(file)) != EOF) {
        curr->str[currBlockLength] = ch;
        currBlockLength++;
        if(currBlockLength == TEXT_BLOCK){
            curr->next = createBlock();
            curr = curr->next;
            currBlockLength = 0;
        }

    }
    curr->str[currBlockLength] = '\0';
    return head;
} 
/*
This function prints the content of the linked list
@param head: the head of the linked list to be created
@return none
*/
void printList(textBlock* head){
    textBlock* curr = head;
    int i = 0;
    int lettersInRow = 0;
    char ch;
    for(curr = head; curr != NULL; curr = curr->next){
        for(i = 0; i < TEXT_BLOCK && (ch = curr->str[i]) != '\0'; i++){
            printf("%c", ch);
            if(ch == '\t'){
                lettersInRow += (8 - lettersInRow % 8);
            }
            if(ch == '\n'){
                lettersInRow = 0;
            }
            if(lettersInRow >= MAX_LINE_LENGTH){
                printf("\n");
                lettersInRow = 0;
            }
            lettersInRow++;
        }

    }
}
/*
This function frees the linked list from the heap memory
@param curr: the current element to be freed
@return none
*/
void freeList(textBlock* curr){
    if(curr){
        freeList(curr->next);
    }
    free(curr);
}