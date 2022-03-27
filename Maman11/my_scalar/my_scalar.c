/*

This program is a part of Mamam11 in the course "Maabada Betihnut maarahot"


*/

#include "functions.h"

int main(){

    int vectorLength = 0;
    int vector1[MAX_VECTOR_LENGTH];
    int vector2[MAX_VECTOR_LENGTH];


    printWelcomeMessage();
    vectorLength = getVectorLength();

    insertToVectors(vector1, vector2, vectorLength);
   
    printf("The scalar multipication of the two vectors is: %d\n", scalar_product(vector1, vector2, vectorLength));
    return 0;
}


