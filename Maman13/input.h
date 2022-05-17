#ifndef INPUT
#define INPUT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_BLOCK 30
#define MAX_ARGUMENT_LENGTH 30
#define SPACE ' '
#define TAB '\t'
#define COMMA ','

void substring(char* string, int length);
char* getInput();
char* getCommand(char* input);
void removeSpacesAndTabs(char* input);
void substring(char* string, int length);
int is_paramater_number(char* parameter);
int foundEOF(char* input);
#endif