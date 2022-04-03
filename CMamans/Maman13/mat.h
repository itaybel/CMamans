
#include <stdio.h>
#include <stdlib.h>
#define MATRIX_SIZE 4
#define HOW_MANY_MATRIXES 6
#define COMMAND_LENGTH_BLOCK 20
#define MAX_COMMANDS 30
#define COMMANDS_LENGTH 7
#define MATRIX_NAME_LENGTH 5
#define INPUT_BLOCK_LENGTH 20
#define ARGUMENT_MAX_LENGTH 20
#define SPACE ' '
#define TAB '\t'

#define MEMORY_BLOCK 15
#define COMMANDS_MEMORY_BLOCK 5
#define COMMA ','
typedef struct mat
{
    double** data;
} mat;

void make_matrix(mat* matrix);
void delete_matrix(mat matrix);
void print_matrix(mat matrix);
void add_matrix(mat matrixA, mat matrixB, mat* matrixC);
void substract_matrix(mat matrixA, mat matrixB, mat* matrixC);
void multiply_matrix(mat matrixA, mat matrixB, mat* matrixC);
void multiply_matrix_scalar(mat matrixA, mat* matrixB, double scalar);


void matrix_transposition(mat matrixA, mat* matrixB);
char* getInput();
int is_paramater_number(char* parameter);
void handle_read_command(char** parameters, int parameters_length, mat* matrixs[]);

void handle_print_command(char** input, mat* matrixs[]);
void handle_add_command(char** input, mat* matrixs[]);
void handle_sub_command(char** input, mat* matrixs[]);
void handle_mul_command(char** input, mat* matrixs[]);
void handle_trans_command(char** input, mat* matrixs[]);
void handle_stop_command(char** input, mat* matrixs[]);

void use_input(char** parameters, int parameters_length, mat** matrixs);
char* getCommand(char* input);
char* removeSpacesAndTabs(char* input, char* command);
char** seperateToArguments(char* input);