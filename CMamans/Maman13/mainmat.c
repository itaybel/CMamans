
#include "header.h"

int main(){
    mat mat_a; 
    mat mat_b;
    mat mat_c; 
    mat mat_d;
    mat mat_e; 
    mat mat_f;
    mat* all_matrixes[HOW_MANY_MATRIXES];
    
    char inputFromUser[MAX_INPUT_LEN];
    char command[MAX_ARGUMENT_LENGTH];

    all_matrixes[0] = &mat_a, all_matrixes[1] = &mat_b, all_matrixes[2] = &mat_c, all_matrixes[3] = &mat_d, all_matrixes[4] = &mat_e, all_matrixes[5] = &mat_f;
    make_matrix(&mat_a, 'A');
    make_matrix(&mat_b, 'B');
    make_matrix(&mat_c, 'C');
    make_matrix(&mat_d, 'D');
    make_matrix(&mat_e, 'E');
    make_matrix(&mat_f, 'F');


    while(strcmp(inputFromUser, "stop") != 0){


        printf("\n> ");

        getInput(inputFromUser);

      
        getCommand(inputFromUser, command);
        printf("got: %s\n", command);
        printf("got2: %s\n", inputFromUser);

        removeSpacesAndTabs(inputFromUser);

        if(inputFromUser[0] == '\n') continue;
        if(foundEOF(inputFromUser)) break;

        handle_command(command ,inputFromUser ,all_matrixes);


}
    return 0;
}