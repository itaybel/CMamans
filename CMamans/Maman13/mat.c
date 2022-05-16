#include "mat.h"

void make_matrix(mat* matrix, char letter){

    int i  = 0;
    matrix->sign = letter;
    matrix->data = (double**)calloc(MATRIX_SIZE, sizeof(double*));
    for(i = 0; i < MATRIX_SIZE; i++){
        (matrix->data)[i] = (double*)calloc(MATRIX_SIZE, sizeof(double));
    }
}

void delete_matrix(mat matrix){
    int i  = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        free((matrix.data)[i]);
    }
    free(matrix.data);
}


void print_matrix(mat matrix){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            printf("%f\t", matrix.data[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixC->data)[i][j] = (matrixA.data)[i][j] + (matrixB.data)[i][j];
        }
    }
}

void substract_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixC->data)[i][j] = (matrixA.data)[i][j] - (matrixB.data)[i][j];
        }
    }
}

void multiply_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    int k = 0;
    double sum = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            sum = 0;
            for(k = 1; k < MATRIX_SIZE; k++){
                sum += (matrixA.data)[i][k] * (matrixB.data)[k][j];
            } 
            (matrixC->data)[i][j] = sum;
        }
    }
}

void multiply_matrix_scalar(mat matrixA, mat* matrixB, double scalar){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixB->data)[i][j] = (matrixA.data)[i][j] * scalar;
        }
    }
}

void matrix_transposition(mat matrixA, mat* matrixB){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixB->data)[i][j] = (matrixA.data)[j][i];
        }
    }
}












