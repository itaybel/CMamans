
#include "mat.h"

int main(){
    mat mat_a; 
    mat mat_b;
    mat mat_c; 
    mat mat_d;
    mat mat_e; 
    mat mat_f;
    mat* all_matrixes[HOW_MANY_MATRIXES];
    char input[INPUT_LEN];
    char* command;
    char** arguments;
    all_matrixes[0] = &mat_a, all_matrixes[1] = &mat_b, all_matrixes[2] = &mat_c, all_matrixes[3] = &mat_d, all_matrixes[4] = &mat_e, all_matrixes[5] = &mat_f;


    getInput(input);

    /*
    command = getCommand(buffer);

  
    buffer = removeSpacesAndTabs(buffer, command);
    arguments = seperateToArguments(buffer);
    use_input(command, arguments ,all_matrixes);
*/
    return 0;
}