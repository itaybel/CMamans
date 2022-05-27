#include <stdarg.h>
#include <stdio.h>
/*
This function will get unlimited number of positive integers, and will return a number which is the and of all of the number's bits
@param count: how many arguments will be sent
@return the result, which is and to all of the numbers
*/
int my_and(unsigned int count, ...){

    unsigned int output;
    unsigned int curr;
    int i = 0;
    va_list ap;

    va_start(ap, count);
    output = va_arg(ap, unsigned int);
    for(i = 1; i < count; i++){
        curr = va_arg(ap, unsigned int);
        output = output & curr;
    }

    return output;

}

int main(){
    int res = 0;
    res = my_and(4, 432432, 3123123 ,1030303, 13231233);
    printf("\nFirst call to funcion: \n--------------\n");
    printf("Arguments are: 432432, 3123123 ,1030303, 13231233\n");
    printf("Result in decimal: %u\nResult in hexdecimal: %#05x\n", res, res);

    res = my_and(2, ~0, ~0);
    printf("Second call to funcion: \n--------------\n");
    printf("Arguments are: 2, %u, %u\n", ~0, ~0);
    printf("Result in decimal: %u\nResult in hexdecimal: %#05x\n", res, res);

    res = my_and(3, ~0, 300, 321);
    printf("Third call to funcion: \n--------------\n");
    printf("Arguments are: 3, %u, 300, 321\n", ~0);
    printf("Result in decimal: %u\nResult in hexdecimal: %#05x\n", res, res);
  
    res = my_and(5, 31231, 123898 ,~0, 93933, 0);
    printf("Fourth call to funcion: \n--------------\n");
    printf("Arguments are: 5, 31231, 123898 ,%u, 93933, 0\n", ~0);
    printf("Result in decimal: %u\nResult in hexdecimal: %#05x\n", res, res);

    return 1;
}