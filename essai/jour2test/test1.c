#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a); //analyse l'entree qui corres aux specificateurs de format
    /*
    Le signe & avant le nom de la variable est l'opérateur d'adresse. Il donne l'adresse ou l'emplacement en memoire d'une variable. Ceci est nécessaire car scanf place une valeur d'entree à une adresse variable
    */
    printf("You entered: %d", a);

    int b;
    printf("\nEnter two numbers:");
    scanf("%d %d", &a, &b);
    
    printf("\nSum: %d", a+b);

    return 0;
}