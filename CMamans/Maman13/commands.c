#include "commands.h"


void handle_read_command(char* input, mat* matrixs[]){
    mat* found_matrix;
    double currArgumentDouble;
    int i = 1;
    int res;
    removeSpacesAndTabs(input);

    found_matrix = getMat(input, matrixs);

    if(found_matrix == NULL) return;


    for(i = 0; i < 16; i++){

         res = consestiveCommasFound(input);
        if(res == 0){
            if(i == 0){
                printf("Missing argument\n");
            }
            break;
        }
        
        if(!isCommasValid(input)){
           
            return;
        }

        substring(input, res);
                removeSpacesAndTabs(input);



        if(getNextNumber(input, &currArgumentDouble) == -2){
            printf("Extra text after command\n");
            return;
        }
        if(getNextNumber(input, &currArgumentDouble) == -1){
            printf("Argument is not a real number\n");
            return;
        }if(getNextNumber(input, &currArgumentDouble) == -3){
            printf("Found more than one decimal point in one arugment\n");
            return;
        }else{
            found_matrix->data[i / MATRIX_SIZE][i  % MATRIX_SIZE] =  currArgumentDouble;
        }
       
        
    }


    print_matrix(*found_matrix);

}
void handle_print_command(char* input, mat* matrixs[]){
    mat* found_matrix = getMat(input, matrixs);
    if(found_matrix == NULL) return;
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }

    print_matrix(*found_matrix);
    

}
void handle_add_command(char* input, mat* matrixs[]){
    mat* first_mat = NULL;
    mat* second_mat = NULL;
    mat* output_mat =  NULL;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));
    printf("cock : %s\n", input);

    removeSpacesAndTabs(input);
    second_mat = getMat(input, matrixs);

    if(second_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));
    printf("cock : %s\n", input);

    removeSpacesAndTabs(input);
    output_mat = getMat(input, matrixs);

    if(output_mat == NULL || !isCommasValid(input)) return;
       substring(input, consestiveCommasFound(input));
    printf("cock : %s\n", input);

    
    
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }
    add_matrix(*first_mat, *second_mat, output_mat);

    return;

}
void handle_sub_command(char* input, mat* matrixs[]){
    return;
}
void handle_mul_command(char* input, mat* matrixs[]){
    return;
}
void handle_trans_command(char* input, mat* matrixs[]){
    return;
}
void handle_stop_command(char* input, mat* matrixs[]){
    return;
}

void handle_command(char* command, char* input , mat* matrixs[]){    
    char commands[COMMANDS_LENGTH][COMMAND_LENGTH_BLOCK] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "trans_mat", "stop"};
    void (*func_ptr[COMMANDS_LENGTH])() = {handle_read_command, handle_print_command, handle_add_command, handle_sub_command, handle_mul_command, handle_trans_command, handle_stop_command};
    int i = 0;
    int found_cmd = 0;


    for(i = 0 ; i < COMMANDS_LENGTH && !found_cmd; i++){
        if(strcmp(commands[i], command) == 0){
            (*func_ptr[i])(input, matrixs);
            found_cmd = 1;
        }
    }

    if(!found_cmd){
        printf("Undefined command name\n");
        return;
    }


     
}

int consestiveCommasFound(char* input){
    int commasFound = 0;
    removeSpacesAndTabs(input);
    if(input[0] == ','){
        removeSpacesAndTabs(input);
        if(input[0] == ','){
            commasFound = 2;
        }
        commasFound = 1;

    }
    return commasFound;
}

int isCommasValid(char* input){
    
    int res = consestiveCommasFound(input);
    if(res == 1) return 1;
    if(res == 0){
        printf("Missing comma\n");
    }else{
        printf("Multiple consecutive commas\n");
    }
    return 0;
    
}



mat* getMat(char* input, mat** all_matrixs){
    char foundMatName[6] = {0};
    char all_matrix_names[HOW_MANY_MATRIXES][MATRIX_NAME_LENGTH + 1] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    int i = 0;
    mat* found_matrix = NULL;
    int found_flag = 0;

    for(i = 0; i < 5; i++){
        foundMatName[i] = input[i];
    }
    foundMatName[5] = '\0';
    substring(input, i);

  
    for(i = 0 ; i < HOW_MANY_MATRIXES; i++){

        if(strcmp(foundMatName, all_matrix_names[i]) == 0){
            found_matrix = (all_matrixs[i]);
            found_flag = 1;
        }
    }
    if(!found_flag){
        printf(" %s - Undefined matrix name\n", foundMatName);
        return NULL;
    }
    return found_matrix;
}



int getNextNumber(char* input, double* pointer){
    char currArgument[MAX_ARGUMENT_LENGTH] = {0};
    int i = 0;
    int decimalPointCounter = 0;
    for(; (input[i] <= '9' && input[i] >= '0') || input[i] == '.' || input[i] == '+' || input[i] == '-'; i++){
        decimalPointCounter += (input[i] == '.');

        if(decimalPointCounter >= 2){
            printf("2 decimal points were found on the same argument!\n");
            return -3;
        }

        currArgument[i] = input[i];
    }

    if(input[i] != ',' && input[i] != '\0'){
        return -1;
    }
    if(i == 0){
        return -2;
    }

    substring(input, i);
    removeSpacesAndTabs(input);
    *pointer = strtod(currArgument, NULL);
    return 0;
    
}

int getCommas(char* command){
    int i = 0;
    for(i = 0; i < strlen(command); i++){
        if(command[i] == ','){
            if(i != strlen(command) && command[i + 1] == ','){
                return 2;
            }
            return 1;
        }
    }
    return 0;
}
