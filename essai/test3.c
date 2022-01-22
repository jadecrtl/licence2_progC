#include <stdio.h>//standard input output qui est une librairie du c

#define PI 3.14 //une autre maniere de definir une constante
//a la fin d'un #define il ne faut pas mettre ;
#define pri printf
int main() {
    pri("%f \n", PI);
    return 0;
}

/*
#define definit des constantes au moment de la compilation.
Elle est geree par le preprocesseur.

const qualifie une variable comme etant "en lecture seule".
C a d que sa valeur n'est pas sensee etre modifiee
*/