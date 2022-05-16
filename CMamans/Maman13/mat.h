#ifndef MAT
#define MAT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_NAME_LENGTH 5
#define MATRIX_SIZE 4
#define HOW_MANY_MATRIXES 6



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
mat* get_matrix_by_string(char* name, mat** all_matrixs);

#endif