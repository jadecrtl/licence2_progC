#include <stdio.h>

int main() {
    int a;
    printf("Entrez un nombre : ");
    scanf("%d", &a); //analyse l'entree qui corres aux specificateurs de format
    /*
    Le signe & avant le nom de la variable est l'opérateur d'adresse. Il donne l'adresse ou l'emplacement en memoire d'une variable. Ceci est nécessaire car scanf place une valeur d'entree à une adresse variable
    */
    printf("Vous avez entre ce nombre : %d", a);

    int c, b;
    printf("\nEnter two numbers:");
    scanf("%d %d", &b, &c);
    
    printf("\nSum: %d\n", b+c);

    return 0;
}