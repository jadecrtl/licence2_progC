#include <stdio.h>

int ajoute1 (int parametreFonction[]) {
    printf("adresse parametreFonction = %p, parametreFonction = %d\n", &parametreFonction, parametreFonction[0]);
    parametreFonction[0] += 1;
    return parametreFonction[0];
}

void ajoute1Void (int parametreFonction[]) {
    printf("adresse parametreFonction = %p, parametreFonction = %d\n", &parametreFonction, parametreFonction[0]);
    parametreFonction[0] += 1;
}

void initTableau (int parametreFonction[], int tailleTableau) {
    for (int i = 0; i < tailleTableau; i++) {
        parametreFonction[i] = 17;
    }
}

void afficheTableau (int parametreFonction[], int tailleTableau) {
    printf("[");
    for (int i = 0; i < tailleTableau - 1; i++) {
        printf("%d, ",parametreFonction[i]);
    }
    printf("%d",parametreFonction[tailleTableau - 1]);
    printf("]\n");
}

int main() {
    int parametre[4] = {0,0,0,0};
    int retour = 0;
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre[0], retour);
    //retour = ajoute1(parametre);
    ajoute1Void(parametre);
    printf("adresse parametre         = %p, parametre = %d, retour = %d\n", &parametre, parametre[0], retour);

    int tableauPasInit[10];
    initTableau(tableauPasInit, 10);
    afficheTableau(tableauPasInit, 10);
    return 0;
}