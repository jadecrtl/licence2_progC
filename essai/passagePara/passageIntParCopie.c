#include <stdio.h>

int ajoute1 (int parametreFonction) {
    printf("adresse parametreFonction = %p, parametreFonction = %d\n", &parametreFonction, parametreFonction);
    return parametreFonction + 1;
}


int main() {
    int parametre = 0;
    int retour = 0;
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre, retour);
    retour = ajoute1(parametre);
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre, retour);
    return 0;
}