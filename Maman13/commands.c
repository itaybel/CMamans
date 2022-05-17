#include "commands.h"

/*
This function handles the read command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
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
                return;
            }
            break;
        }
        
        if(!isCommasValid(input)){
           
            return;
        }

        substring(input, res);
        removeSpacesAndTabs(input);


        res = getNextNumber(input, &currArgumentDouble);
       
        if(res == -1){
            printf("Argument is not a real number!\n");
            return;
        }if(res == -2){
            printf("Found more than one decimal point in one arugment\n");
            return;
        }else{
            found_matrix->array[i / MATRIX_SIZE][i  % MATRIX_SIZE] =  currArgumentDouble;
        }
       
        
    }

    printf("The matrix now is: \n");
    print_matrix(*found_matrix);

}
/*
This function handles the print command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
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
/*
This function handles the add command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void handle_add_command(char* input, mat* matrixs[]){
    mat* first_mat = NULL;
    mat* second_mat = NULL;
    mat* output_mat =  NULL;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    second_mat = getMat(input, matrixs);

    if(second_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    output_mat = getMat(input, matrixs);

    if(output_mat == NULL) return;
    
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }
    add_matrix(*first_mat, *second_mat, output_mat);

    printf("Successfully added the 2 matrixes!\nThe result matrix is: \n");
    print_matrix(*output_mat);



}
/*
This function handles the sub command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void handle_sub_command(char* input, mat* matrixs[]){
    mat* first_mat = NULL;
    mat* second_mat = NULL;
    mat* output_mat =  NULL;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    second_mat = getMat(input, matrixs);

    if(second_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    output_mat = getMat(input, matrixs);

    if(output_mat == NULL) return;
    
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }
    substract_matrix(*first_mat, *second_mat, output_mat);
    printf("Successfully substraced the 2 matrixes!\nThe result matrix is: \n");
    print_matrix(*output_mat);

}
/*
This function handles the mul command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void handle_mul_command(char* input, mat* matrixs[]){
        mat* first_mat = NULL;
    mat* second_mat = NULL;
    mat* output_mat =  NULL;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    second_mat = getMat(input, matrixs);

    if(second_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);
    output_mat = getMat(input, matrixs);

    if(output_mat == NULL) return;
    
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }
    multiply_matrix(*first_mat, *second_mat, output_mat);
    printf("Successfully multiplied the 2 matrixes!\nThe result matrix is: \n");
    print_matrix(*output_mat);
}
/*
This function handles the trans command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void handle_trans_command(char* input, mat* matrixs[]){
    mat* first_mat = NULL;
    mat* output_mat =  NULL;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));


    removeSpacesAndTabs(input);
    output_mat = getMat(input, matrixs);

    if(output_mat == NULL) return;
    
    removeSpacesAndTabs(input);
    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }
    matrix_transposition(*first_mat, output_mat);
    printf("Successfully transposed the matrixe!\nThe result matrix is: \n");
    print_matrix(*output_mat);
}
/*
This function handles the mul scalar command.
@param input: the line which the user has written,
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void handle_mul_scalar_command(char* input, mat* matrixs[]){
    mat* first_mat = NULL;
    mat* output_mat =  NULL;
    double scalar = 1;
    int res = 0;

    removeSpacesAndTabs(input);
    first_mat = getMat(input, matrixs);
    if(first_mat == NULL || !isCommasValid(input)) return;
    substring(input, consestiveCommasFound(input));

   
    removeSpacesAndTabs(input);

    res = getNextNumber(input, &scalar);
    if(res == -1){
        printf("Argument is not a real number!\n");
        return;
    }if(res== -2){
        printf("Found more than one decimal point in one arugment\n");
        return;
    }


    substring(input, consestiveCommasFound(input));

    removeSpacesAndTabs(input);

    output_mat = getMat(input, matrixs);
    if(output_mat == NULL) return;

    if(input[0] != '\0'){
        printf("Extra text after command\n");
        return;
    }

    multiply_matrix_scalar(*first_mat, output_mat, scalar);
    printf("Successfully multiplied by scalar!\nThe result matrix is: \n");
    print_matrix(*output_mat);
}



/*
This function handles the input from the user.
@param command: the command the user has written
@param input: the input the user has written, without the command
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return wether the program should be terminated or not
0 - its should be termniated
1 - its not should be terminated
*/
int handle_command(char* command, char* input , mat* matrixs[]){    
    char commands[COMMANDS_LENGTH][COMMAND_LENGTH_BLOCK] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat","mul_scalar" ,"trans_mat"};
    void (*func_ptr[COMMANDS_LENGTH])() = {handle_read_command, handle_print_command, handle_add_command, handle_sub_command, handle_mul_command, handle_mul_scalar_command ,handle_trans_command};
    int i = 0;
    int found_cmd = 0;

    if(strcmp(command, "stop") == 0){
        removeSpacesAndTabs(input);
        if(input[0] != '\0'){
            printf("Extra text after command\n");
            return 1;
        }
        printf("Bye bye!\n");
        return 0;
     }

    

    for(i = 0 ; i < COMMANDS_LENGTH && !found_cmd; i++){

        if(strcmp(commands[i], command) == 0){
            (*func_ptr[i])(input, matrixs);
            found_cmd = 1;
        }
    }

    if(!found_cmd){
        printf("Undefined command name\n");
    }
    return 1;


     
}
/*
This function checks how many consestive commas are there at the beginning of a string
@param input: the input the user has written after some configurtions
@return 
0 - if no commas were found
1 - if one commas were found
2 - if 2 commas were found
*/
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
/*
This function checks wether the commas at the beginning of a string are valid, and prints responses to the user
@param input: the input the user has written after some configurtions
@return wether its valid or not
*/
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


/*
This function returnes a mat struct pointer, according to the beginning of a string.
@param input: the input the user has written after some configurtions
@param matrixs: an array of the matrix struct, which contains information about the matrixes

@return a pointer to the suitable matrix
*/
mat* getMat(char* input, mat** all_matrixs){
    char foundMatName[6] = {0};
    char all_matrix_names[HOW_MANY_MATRIXES][MATRIX_NAME_LENGTH + 1] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    int i = 0;
    mat* found_matrix = NULL;
    int found_flag = 0;
    for(i = 0; i < 5 && input[i] != '\0'; i++){
        foundMatName[i] = input[i];
    }
    substring(input, i);
    if(i == 0){
        printf("Missing argument\n");
        return NULL;
    }
    foundMatName[5] = '\0';

  
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



/*
This function gets the next number in a string and stores it in a variable
@param input: the input the user has written after some configurtions
@param pointer: a pointer to the variable which will be changed
@return
-2 if 2 decimal points were found on the same argument
-1 if  argument is not a real number
*/
int getNextNumber(char* input, double* pointer){
    char currArgument[MAX_ARGUMENT_LENGTH] = {0};
    int i = 0;
    int decimalPointCounter = 0;

    for(; (input[i] <= '9' && input[i] >= '0') || input[i] == '.' || input[i] == '+' || input[i] == '-'; i++){
        decimalPointCounter += (input[i] == '.');

        if(decimalPointCounter >= 2){
            return -2;
        }

        currArgument[i] = input[i];
    }

    if(input[i] != ',' && input[i] != '\0' && input[i] != ' '){
        return -1;
    }
    

    substring(input, i);
    removeSpacesAndTabs(input);

    *pointer = strtod(currArgument, NULL);
    return 0;
    
}

/*
This function frees all the matrixes memory
@param matrixs: an array of the matrix struct, which contains information about the matrixes
@return none
*/
void freeMatrixsMemory(mat* matrixs[]){
    int i = 0;
    for(i = 0; i < HOW_MANY_MATRIXES; i++){
        free(matrixs[i]);
    }
    
}