#include "mat.h"

/*
This function creates a matrix
@param letter: the letter represents the matrix
@return a pointer to the allocated memory
*/
mat* make_matrix(char letter){

    return (mat*)calloc(1, sizeof(mat));
}



/*
This function prints a matrix
@param matrix: the matrix to be printed
@return none
*/
void print_matrix(mat matrix){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            printf("%f\t", matrix.array[i][j]);
        }
        printf("\n");
    }
}
/*
This function adds 2 matrixes and stores the results in a third matrix.
@param matrixA: the first matrix to be added
@param matrixB: the second matrix to be added
@param matrixc: the matrix to be changed

@return none
*/
void add_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixC->array)[i][j] = (matrixA.array)[i][j] + (matrixB.array)[i][j];
        }
    }
}
/*
This function substracts 2 matrixes and stores the results in a third matrix.
@param matrixA: the first matrix to be added
@param matrixB: the second matrix to be added
@param matrixc: the matrix to be changed

@return none
*/
void substract_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixC->array)[i][j] = (matrixA.array)[i][j] - (matrixB.array)[i][j];
        }
    }
}
/*
This function multiplies 2 matrixes and stores the results in a third matrix.
@param matrixA: the first matrix to be added
@param matrixB: the second matrix to be added
@param matrixc: the matrix to be changed

@return none
*/
void multiply_matrix(mat matrixA, mat matrixB, mat* matrixC){
    int i = 0;
    int j = 0;
    int k = 0;
    double sum = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            sum = 0;
            for(k = 0; k < MATRIX_SIZE; k++){
                sum += (matrixA.array)[i][k] * (matrixB.array)[k][j];
            } 
            (matrixC->array)[i][j] = sum;
        }
    }
}
/*
This function adds multiplies a matrix by a scalar and stores the result in a third matrix
@param matrixA: the first matrix to be added
@param matrixB: the matrix to be changed
@param scalar: to scalar to be multiplied

@return none
*/
void multiply_matrix_scalar(mat matrixA, mat* matrixB, double scalar){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixB->array)[i][j] = (matrixA.array)[i][j] * scalar;
        }
    }
}
/*
This function adds transposes a matrix and stores the result in another matrix
@param matrixA: the matrix to be transposed
@param matrixB: the matrix to be changed

@return none
*/
void matrix_transposition(mat matrixA, mat* matrixB){
    int i = 0;
    int j = 0;
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            (matrixB->array)[i][j] = (matrixA.array)[j][i];
        }
    }
}












