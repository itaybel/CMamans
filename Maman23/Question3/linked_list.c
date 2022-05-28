#include "linked_list.h"
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
    fclose(file);

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

    printf("The file content in a pretty format: \n\n");

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