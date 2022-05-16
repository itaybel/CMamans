#ifndef INPUT
#define INPUT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGUMENTS 30
#define MAX_ARGUMENT_LENGTH 20
#define MAX_INPUT_LEN 100
#define SPACE ' '
#define TAB '\t'
#define COMMA ','

void substring(char* string, int length);
void getInput(char buffer[MAX_INPUT_LEN]);
void getCommand(char input[MAX_INPUT_LEN], char command[MAX_ARGUMENT_LENGTH]);
void removeSpacesAndTabs(char* input);
void substring(char* string, int length);
int is_paramater_number(char* parameter);
int foundEOF(char* input);
#endif