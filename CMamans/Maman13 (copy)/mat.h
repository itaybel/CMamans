
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MATRIX_SIZE 4
#define HOW_MANY_MATRIXES 6
#define COMMAND_LENGTH_BLOCK 20
#define COMMANDS_LENGTH 7
#define MATRIX_NAME_LENGTH 5
#define INPUT_LEN 100
#define SPACE ' '
#define TAB '\t'

#define MEMORY_BLOCK 15
#define COMMA ','
typedef struct mat
{
    double** data;
    char sign;
} mat;


void make_matrix(mat* matrix, char letter);
void delete_matrix(mat matrix);
void print_matrix(mat matrix);
void add_matrix(mat matrixA, mat matrixB, mat* matrixC);
void substract_matrix(mat matrixA, mat matrixB, mat* matrixC);
void multiply_matrix(mat matrixA, mat matrixB, mat* matrixC);
void multiply_matrix_scalar(mat matrixA, mat* matrixB, double scalar);


void matrix_transposition(mat matrixA, mat* matrixB);
void getInput(char* input);int is_paramater_number(char* parameter);

void handle_read_command(char** arguments, mat* matrixs[]);
void handle_print_command(char** arguments, mat* matrixs[]);
void handle_add_command(char** arguments, mat* matrixs[]);
void handle_sub_command(char** input, mat* matrixs[]);
void handle_mul_command(char** input, mat* matrixs[]);
void handle_trans_command(char** input, mat* matrixs[]);
void handle_stop_command(char** input, mat* matrixs[]);

int foundComma(char* str);
void use_input(char* command, char** arguments , mat* matrixs[]);
char* getCommand(char* input);
char* removeSpacesAndTabs(char* input, char* command);
char** seperateToArguments(char* input);
int countCommas(char* input);