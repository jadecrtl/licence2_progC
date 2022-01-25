#include <stdio.h>

int main(int argc, char **argv) {
    float a = 6.50;
    int b = 2;
    float c;

    c = a + b;
    
    printf("New price is %4.2f\n", c);
    /* 
    4.2f : le 4 permet de faire un décallage de 4 - (la taille de ce qu'il sera affiché apres) espaces avant l'affichage de la variable. Le .2 permet de limiter l'affichage du nombre a 2 chiffres.
    */

    float d;
    int e = 23;
    int f = 4;

    d = (float) e / f;

    printf("Le resultat est %4.3f", d);

    return 0;
}