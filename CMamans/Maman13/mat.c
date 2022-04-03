#include "mat.h"
#include <string.h>

void make_matrix(mat* matrix){

    int i  = 0;
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




    

int is_paramater_number(char* parameter){
    int flag = 1;
    int i = 0;
    for(i = 0; *(parameter + i) != '\0'; i++){
        if('9' < *(parameter + i) || *(parameter + i) < '0') flag = 0;
    }
    return flag;
}

mat* get_matrix_by_string(char* name, mat** all_matrixs){
    char all_matrix_names[HOW_MANY_MATRIXES][MATRIX_NAME_LENGTH + 1] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    int i = 0;
    mat* found_matrix = NULL;
    int found_flag = 0;
    
    printf("liam I am here");
    for(i = 0 ; i < HOW_MANY_MATRIXES; i++){
    printf("now I am here");

        if(strcmp(name, all_matrix_names[i]) == 0){
            found_matrix = (all_matrixs[i]);
            found_flag = 1;
        }
    }
    if(!found_flag){
        printf("Undefined matrix name");
        return NULL;
    }
    return found_matrix;
}

void handle_read_command(char** parameters, int parameters_length, mat* matrixs[]){
    int i = 0;
    mat* found_matrix = get_matrix_by_string(parameters[1], matrixs);

    if(found_matrix == NULL) return;

    for(i = 2; i < parameters_length; i++){
        if(!is_paramater_number(parameters[i])){
            printf("Argument is not a real number");
            return;
        }
        
        found_matrix->data[(i - 2) / MATRIX_SIZE][(i - 2) % MATRIX_SIZE] = atof(parameters[i]);
        
    }

}
void handle_print_command(char** parameters, mat* matrixs[]){
    /* mat* found_matrix = get_matrix_by_string(parameters[1], matrixs); */
}
void handle_add_command(char** input, mat* matrixs[]){
    return;
}
void handle_sub_command(char** input, mat* matrixs[]){
    return;
}
void handle_mul_command(char** input, mat* matrixs[]){
    return;
}
void handle_trans_command(char** input, mat* matrixs[]){
    return;
}
void handle_stop_command(char** input, mat* matrixs[]){
    return;
}

void use_input(char** parameters, int parameters_length, mat* matrixs[]){
    
    char commands[COMMANDS_LENGTH][COMMAND_LENGTH_BLOCK] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "trans_mat", "stop"};
    void (*func_ptr[COMMANDS_LENGTH])() = {handle_read_command, handle_print_command, handle_add_command, handle_sub_command, handle_mul_command, handle_trans_command, handle_stop_command};
    int i = 0;
    int found_cmd = 0;

    for(i = 0; i < parameters_length; i++){
        printf("%s\n", *(parameters + i));
    }
    for(i = 0 ; i < COMMANDS_LENGTH && !found_cmd; i++){
        if(strcmp(commands[i], parameters[0]) == 0){
            (*func_ptr[i])(parameters, matrixs, parameters_length);
            found_cmd = 1;
        }
    }

    if(!found_cmd){
        printf("Undefined command name");
    }
    
}
char* getInput(mat* matrixs[]){

    char* buffer = (char*)malloc(sizeof(char) * MEMORY_BLOCK);
    int length = 0;
    int currentBlockLength = 1;
    char currChar;
    while((currChar = getchar()) != EOF){
        *(buffer + length) = currChar;
        if(currentBlockLength >= MEMORY_BLOCK){
            buffer = (char*)realloc(buffer, (length  + MEMORY_BLOCK) * sizeof(char));
            currentBlockLength= 0;
        }

        currentBlockLength++;
        length++;
    }
    
    return buffer;

}



char* getCommand(char* input){
    char* command = (char*)calloc(MEMORY_BLOCK, sizeof(char));
    int i = 0;
    char currChar;
    for(i = 0; (currChar = *(input + i)) != SPACE && currChar != TAB && i < strlen(input) ; i++){
        if(i % MEMORY_BLOCK == 0){
            command = (char*)realloc(command, sizeof(char) * (i + MEMORY_BLOCK));
        }
        *(command + i) = currChar;
    }
    return command;
}


char* removeSpacesAndTabs(char* input, char* command){
    int i = 0;

    char* clear_input = (char*)malloc(sizeof(char) * MEMORY_BLOCK);
    int length = 0;
    char currChar;
    for(i = strlen(command); i < strlen(input); i++){
        currChar = input[i];
        if(currChar == SPACE || currChar == TAB) continue;
        clear_input[length] = currChar;
        length++;
        if(length % MEMORY_BLOCK == 0){
            clear_input = (char*)realloc(clear_input, (length  + MEMORY_BLOCK) * sizeof(char));
        }
    }
    
    return clear_input;

}

int countCommas(char* input){
    int counter = 0;
    int i = 0;
    for(i = 0; i < strlen(input); i++){
        if(input[i] == COMMA) counter++;
    }
    return counter;
}

char** seperateToArguments(char* input){
    if(countCommas(input) == 0) return NULL;
    char** arguments = (char**)malloc(sizeof(char*) * (countCommas(input) + 1));
    const char devider[2] = ",";
    char* token = strtok(input, devider);
    int i = 0;
    while(token != NULL){
        arguments[i] = token;
        printf("\n%d: %s", i,token);
        token = strtok(NULL, devider);
        i++;
    }
    return arguments;
}