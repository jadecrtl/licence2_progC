#include <stdio.h>

int main() {
    printf("int: %ld %d \n", sizeof(int), 25);//on peut mettre plusieurs % 
    printf("float: %ld \n", sizeof(float));
    printf("double: %ld \n", sizeof(double));
    printf("char: %ld \n", sizeof(char));
    printf("hello \n");
    return 0;
}