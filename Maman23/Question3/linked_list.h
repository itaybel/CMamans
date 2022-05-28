
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define TEXT_BLOCK 5
#define MAX_LINE_LENGTH 20

typedef struct textBlock{

    char str[TEXT_BLOCK];
    struct textBlock* next;

} textBlock;

textBlock* createBlock();
textBlock* extractFileContent(char* file_name);
void printList(textBlock* head);
void freeList(textBlock* curr);

