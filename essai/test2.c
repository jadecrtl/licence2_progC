#include <stdio.h>

int main() {
    int a, b;
    float salary = 56.23;
    char letter = 'Z';
    a = 8;
    b = 34;
    int c = a + b;

    printf("%d \n", c);
    printf("%f \n", salary);
    printf("%c \n", letter);

    const double PI = 3.14;//Une constante stocke une valeur qui ne peut pas etre modifiee depuis son affectation initiale
    printf("%f", PI);


    return 0;
}