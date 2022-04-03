
#include "mat.h"

int main(){
    mat mat_a; 
    mat mat_b;
    mat mat_c; 
    mat mat_d;
    mat mat_e; 
    mat mat_f;
    mat* all_matrixes[HOW_MANY_MATRIXES];
    char* buffer;
    char* command;
    char** arguments;
    all_matrixes[0] = &mat_a, all_matrixes[1] = &mat_b, all_matrixes[2] = &mat_c, all_matrixes[3] = &mat_d, all_matrixes[4] = &mat_e, all_matrixes[5] = &mat_f;
    make_matrix(&mat_a);
    make_matrix(&mat_b);
    make_matrix(&mat_c);
    make_matrix(&mat_d);
    make_matrix(&mat_e);
    make_matrix(&mat_f);

    buffer = getInput();
    command = getCommand(buffer);
    buffer = removeSpacesAndTabs(buffer, command);
    arguments = seperateToArguments(buffer);
    
    return 0;
}