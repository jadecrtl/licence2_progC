#include <stdio.h>
#include <stdlib.h>

#define NBC 10

enum etat {VALIDEE, ENCOURS, EXPEDIEE};
typedef enum etat etat;
struct commande {
    int num_com;
    int prix_exp;
    int prix_prod;
    etat etat_com;
};
typedef struct commande commande;

commande com_alea(int num) {
    etat e;
    switch(rand() % 3) {
    case 0:
        e = VALIDEE;
        break;
    case 1:
        e = ENCOURS;
        break;
    case 2:
        e = EXPEDIEE;
        break;    
    }
    commande com;
    com.num_com = num;
    com.prix_exp = rand() % 20;
    com.prix_prod = rand() % 2000;
    com.etat_com = e;
    return com;
}

void affiche_com(commande c) {
    printf("Le numero de la commande est %d\n", c.num_com);
    printf("Le prix exp de la commande est %d\n", c.prix_exp);
    printf("Le prix prod de la commande est %d\n", c.prix_prod);
    switch(c.etat_com) {
        case VALIDEE :
            printf("La commande est VALIDEE\n");
            break;
        case ENCOURS : 
            printf("La commande est ENCOURS\n");
            break;
        case EXPEDIEE :
            printf("La commande est EXPEDIEE\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    commande c = com_alea(1002);
    commande tab[NBC];
    affiche_com(c);
}