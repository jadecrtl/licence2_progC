#include <stdio.h>

typedef struct {
    int a;
    int b;
} structJade;

structJade ajoute1 (structJade parametreFonction) {
    printf("adresse parametreFonction = %p, parametreFonction = %d\n", &parametreFonction, parametreFonction.a);
    parametreFonction.a += 1;
    return parametreFonction;
}


int main() {

    structJade parametre = {.a = 0};
    structJade retour = {.a = 0};
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre.a, retour.a);
    retour = ajoute1(parametre);
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre.a, retour.a);
    return 0;
}