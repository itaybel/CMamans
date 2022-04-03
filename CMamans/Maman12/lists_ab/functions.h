#include <stdio.h>
#include <stdlib.h>

#define MEMORY_BLOCK 40
#define LINE_LENGTH 25


void printWelcomeMessage();

int getInput(char** input);

void printInPrettyFormat(char* text, int length);

int countAlphaNumericCharacters(char* letters, int length);

int isAlphaNumeric(char letter);

void printAlphaNumericSum(char* letters, int length);
