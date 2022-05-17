
#include "header.h"

/*
This function prints the menu to the user
@return none
*/
void printMenu(){
    printf("Welcome to Maman22!\nIn this program you can manipulate and play with matrixes!\nHere are the commands:\n");
    printf("\n\tprint_mat MATRIX_NAME - prints the matrix into the screen");
    printf("\n\n\tread_mat MATRIX_NAME, arg1, arg2 ... - feels the given matrix with the given arguments.");
    printf("\n\n\tadd_mat MATRIX1_NAME MATRIX2_NAME MATRIX3_NAME - adds MATRIX1 and MATRIX2 and stores the result in MATRIX3");
    printf("\n\n\tsub_mat MATRIX1_NAME MATRIX2_NAME MATRIX3_NAME - substracts MATRIX1 and MATRIX2 and stores the result in MATRIX3");
    printf("\n\n\tmul_mat MATRIX1_NAME MATRIX2_NAME MATRIX3_NAME - muliplies MATRIX1 and MATRIX2 and stores the result in MATRIX3");
    printf("\n\n\tmul_scalar MATRIX1_NAME SCALAR MATRIX2_NAME - muliplies MATRIX1 by the SCALAR,  and stores the result in MATRIX2");
    printf("\n\n\ttrans_mat MATRIX1_NAME MATRIX2_NAME - transposes MATRIX1 and stores the result in MATRIX2\n");
    printf("\n\nThe matrix names are: MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F");

}

int main(){
    



    mat* all_matrixes[HOW_MANY_MATRIXES] = {0};

    
    char* inputFromUser;
    char* command;
    int running = 1;

    all_matrixes[0] = make_matrix('A');
    all_matrixes[1] = make_matrix('B');
    all_matrixes[2] = make_matrix('C');
    all_matrixes[3] = make_matrix('D');
    all_matrixes[4] = make_matrix('E');
    all_matrixes[5] = make_matrix('F');
  
    printMenu();
    while(running){


        printf("\n> ");

        inputFromUser = getInput();
        printf("You have entered: %s\n", inputFromUser);


        command = getCommand(inputFromUser);
        substring(inputFromUser, strlen(command));

        removeSpacesAndTabs(inputFromUser);

        if(inputFromUser[0] == '\n') continue;
        if(foundEOF(inputFromUser)){
            running = 0;
        }

        running = handle_command(command ,inputFromUser ,all_matrixes);
        
        free(command);
        free(inputFromUser);    

}
    freeMatrixsMemory(all_matrixes);
    return 0;
}