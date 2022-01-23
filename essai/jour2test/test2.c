#include <stdio.h>

int main() {
    /*char a = getchar();

    printf("You entered: ");
    putchar(a); //outputs a single character
    */
    char b[100];
    
    gets(b);
    
    printf("You entered: ");
    puts(b);//this function is used to display output as a string

    return 0;
}