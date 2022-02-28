#include <stdio.h>
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

commande com_alea(int num){
    etat e ;
    switch (rand()%3)
    {
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
    commande c = { 
        .etat_com = e,
        .prix_exp = rand()%19+1,
        .prix_prod = rand()%1999+1,
        .num_com = num,
    };
    return c;
}

void affiche_com(commande c){
    printf("numéro commande : %d \n",c.num_com);
    printf("prix d'expedition : %d \n",c.prix_exp);
    printf("prix de production : %d \n",c.prix_prod);
    switch (c.etat_com){
    case VALIDEE:
        printf("etat : VALIDEE \n");
        break;
    case ENCOURS:
        printf("etat : ENCOURS \n");
        break;
    case EXPEDIEE:
        printf("etat : EXPEDIEE \n");
        break;        
    }
}

void affiche_exp(commande t[], int taille){
    for (int i = 0; i < taille; i++){
        if(t[i].etat_com > 1){
            affiche_com(t[i]);
        }
    }
    
}

int nbr_en_cours(commande t[], int taille){
    int cpt = 0;
    for (int i = 0; i < taille; i++){
        if(t[i].etat_com == 1){
            cpt++;
        }
    }
    
    return cpt;
}

int cout_validees(commande t[],int taille){
    int prix = 0;
    for (int i = 0; i < taille; i++){
        if(t[i].etat_com == 0){
            prix += t[i].prix_exp;
        }
    }
    return prix;
}

int main(){
    srand(time(NULL));
    commande c = com_alea(1002);
    commande tab[NBC];
    affiche_com(c);

    for (int i = 0; i < sizeof(tab)/sizeof(tab[0]); i++){
        tab[i] = com_alea(i+1000);
    }
    
    /*for (int i = 0; i < sizeof(tab)/sizeof(tab[0]); i++){
        affiche_com(tab[i]);
    }*/

    affiche_exp(tab,NBC);

    printf("nombre de commande en préparation : %d \n",nbr_en_cours(tab,NBC));
    printf("prix d'expedition des commandes validées : %d \n",cout_validees(tab,NBC));
}