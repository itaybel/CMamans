#include "functions.h"
/*
This function is used to calculate the scalar multipication of two given vectors.
@param vector1 the first vector 
@param vector2 the second vector 
@param length the length of the two vectors
@return the scalar product of the two vectors
*/
int scalar_product(int vector1[], int vector2[], int length){

    int dot_product = 0;
    int i = 0;
    for(i = 0; i < length; i++){
        dot_product += (vector1[i] * vector2[i]);
    }
    return dot_product;

}

/*
This function is used to fill an empty array with values from the user.
@param vector the vector to be filled
@param length the length of the vectors

*/
void insertToVectors(int vector1[], int vector2[], int length){
    int i = 0;

    printf("Cool!\nthe vector length is %d.\nnow please enter the first vector's values one by one:\n", length);

    for(i = 0; i < length; i++){
        scanf("%d", &vector1[i]);
        printf("entered: %d\n", vector1[i]);

    }
    printf("Great!\nnow please enter the second vector's values one by one:\n");
    
    for(i = 0; i < length; i++){
        scanf("%d", &vector2[i]);
        printf("entered: %d\n", vector2[i]);

    }
}

/*
This function is used to print the welcome message to the user
*/
void printWelcomeMessage(){

    printf("Hello!\nWelcome to the first question of Mamam11!\nPlease enter the length of the vectors: (up to %d) ", MAX_VECTOR_LENGTH);

}

/*
This function is used to get the vector length from the user
@param vector the vector to be filled
@param length the length of the vectors
@return the length of the vector

*/
int getVectorLength(){
    int input = 0;
    scanf("%d", &input);
    return input;
}
