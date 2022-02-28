#include <stdio.h>

int ajoute1 (int *parametreFonction) {
    printf("adresse parametreFonction = %p, parametreFonction = %d\n", parametreFonction, *parametreFonction);
    *parametreFonction += 1;
    return *parametreFonction;
}


int main() {
    int parametre = 0;
    int *adresseParametre = &parametre; 
    int retour = 0;
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", adresseParametre, parametre, retour);
    retour = ajoute1(adresseParametre);
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", adresseParametre, parametre, retour);
    return 0;
}