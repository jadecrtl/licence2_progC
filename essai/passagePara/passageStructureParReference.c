#include <stdio.h>

typedef struct {
    int a;
    int b;
} structJade;

void ajoute1 (structJade *parametreFonction) {
    printf("adresse avant parametreFonction = %p, parametreFonction = %d\n", parametreFonction, parametreFonction->a);
    parametreFonction->a = parametreFonction->a + 1;
    printf("adresse apres parametreFonction = %p, parametreFonction = %d\n", parametreFonction, parametreFonction->a);
}


int main() {
    structJade parametre = {.a = 0};
    structJade *adresseParametre = &parametre;
    printf("adresse parametre         = %p, parametre = %d\n", adresseParametre, parametre.a);
    ajoute1(adresseParametre);
    printf("adresse parametre         = %p, parametre = %d\n", adresseParametre, parametre.a);
    return 0;
}