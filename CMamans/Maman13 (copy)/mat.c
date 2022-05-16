#include "mat.h"
#include <string.h>

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
    for(i = 0 ; i < HOW_MANY_MATRIXES; i++){

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

void handle_read_command(char** parameters, mat* matrixs[]){
    mat* found_matrix = get_matrix_by_string(parameters[0], matrixs);
    char* currArgument;
    int i = 1;
    if(found_matrix == NULL) return;


    while(strcmp((currArgument = parameters[i]), "END") != 0){
        if(!is_paramater_number(currArgument)){
            printf("Argument is not a real number");
            return;
        }

        if(i > MATRIX_SIZE * MATRIX_SIZE){
            printf("Too much arguments!");
            return;
        }
        printf("cock %f\n", atof(currArgument));
        found_matrix->data[(i - 1) / MATRIX_SIZE][(i - 1)  % MATRIX_SIZE] = atof(currArgument); 
        i++;
        
    }

    print_matrix(*found_matrix);

}
void handle_print_command(char** arguments, mat* matrixs[]){
    mat* found_matrix = get_matrix_by_string(arguments[0], matrixs);

    print_matrix(*found_matrix);
    

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

int foundComma(char* str){
    int i = 0;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == ',') return 1;
    }
    return 0;
}

void use_input(char* command, char** arguments , mat* matrixs[]){    
    char commands[COMMANDS_LENGTH][COMMAND_LENGTH_BLOCK] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "trans_mat", "stop"};
    void (*func_ptr[COMMANDS_LENGTH])() = {handle_read_command, handle_print_command, handle_add_command, handle_sub_command, handle_mul_command, handle_trans_command, handle_stop_command};
    int i = 0;
    int found_cmd = 0;


    for(i = 0 ; i < COMMANDS_LENGTH && !found_cmd; i++){
        if(strcmp(commands[i], command) == 0){
            (*func_ptr[i])(arguments, matrixs);
            found_cmd = 1;
        }
    }

    if(!found_cmd){
        if(foundComma(command)){
            printf("Illegal comma");
        }else{
            printf("Undefined command name");
        }
    }
    
}
void getInput(char* input){

    if(fgets(input, INPUT_LEN, stdin) == NULL){
        printf("ERROR, you need to write something");
    }
    input[strcspn(input, "\n")] = 0; 
    

}



char* getCommand(char* input){
    int indexOfSpace = 0;
    int i = 0;
    char* command;
    if(strchr(input, ' ') == NULL){
        printf("No space found!\n");
        return "ERROR";
    }
    indexOfSpace = (int)(strchr(input, ' ') - input);
    command = (char*)malloc((indexOfSpace + 1) * sizeof(char));
    for(i = 0; i < indexOfSpace; i++){
        *(command + i) = input[i];
    }
    command[indexOfSpace] = '\0';
    return command;
}


char* removeSpacesAndTabs(char* input, char* command){
    int i = 0;

    char* clear_input = (char*)malloc(sizeof(char) * (strlen(input) - strlen(command) + 1));
    int length = 0;
    char currChar;
    for(i = strlen(command); i < strlen(input) ; i++){
        currChar = input[i];

        if(currChar == SPACE || currChar == TAB) continue;

        clear_input[length] = currChar;
        length++;

    }
    free(input);
    clear_input = (char*)realloc(clear_input, length);

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

    char** arguments;
    const char devider[2] = ",";
    char* token;
    int i = 0;

    token =  strtok(input, devider);
    arguments = (char**)malloc(sizeof(char*));

    while(token != NULL){
        arguments[i] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(arguments[i], token);

        token = strtok(NULL, devider);
        i++;
        arguments = (char**)realloc(arguments, ((i+1) * sizeof(char*)));

        printf("curr: %s\n", arguments[i - 1]);
    }
    
    arguments[i] = "END";
            printf("curr: %s\n", arguments[i]);

    return i == 0 ? NULL : arguments;
}