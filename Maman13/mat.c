#include <mat.h>
#include <string.h>
mat make_matrix(){
    mat created_matrix;
    created_matrix.data = (double*)calloc(MATRIX_SIZE * MATRIX_SIZE, sizeof(double));
    return created_matrix;
}

void getInput(){
    
}
void handle_command(char command[]){
    if(strcmp(command, READ_COMMAND) == 0){

    }
}