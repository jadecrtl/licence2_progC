/** 
 * fichier contenant les definitions des fonctions données dans polynomes.h 
 * **/
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

#include"polynomes.h"

/*cree le premier maillon factice et retourne son adresse*/
polynome* creer_polynome_vide() {
	polynome* nouvelElement = malloc(sizeof(polynome));
	nouvelElement -> coef = 0;
	nouvelElement -> degre = -1;
	nouvelElement -> suiv = NULL;
	return nouvelElement;
}

/*cree un maillon de coefficient c et degre d*/
polynome* creer_monome(double c, int d) {
	if (c == 0) {
		printf("On ne peut pas créer un monome avec un coef à 0");
		return NULL;
	}
	polynome* nouveauMonome = malloc(sizeof(polynome));
	nouveauMonome -> coef = c;
	nouveauMonome -> degre = d;
	nouveauMonome -> suiv = NULL;
	return nouveauMonome;
}

/*
 * ajoute un monome cX^d au polynome p.
 * Il faut preserver les conventions sur le polynome p
 * Attention notamment au cas ou un monome de meme degré existe deja dans p
 */ 
void ajouter_monome (polynome* p , double c, int d) {
	if (c == 0) {
		printf("Il ne peut pas y avoir un monome avec un coef à 0");
	}
	polynome* ajout = creer_monome(c,d);
	polynome* tmp = p;
	for (tmp; d < tmp -> degre; tmp = tmp -> suiv) {
		if (d == tmp -> degre) {
			tmp -> coef = c + tmp -> coef;
		}
	}

	
}

void annuler(polynome* p) {
	polynome *aux1 = p -> suiv, *aux2;
	while(aux1 != NULL) {
		aux2 = aux1;
		aux1 = aux1 -> suiv;
		free(aux2);
	}
	p -> suiv = NULL;
}


void test(){	
	polynome* p = creer_polynome_vide();
	printf("Le coef de p est %f et le degré de p est %d \n", p->coef, p->degre);
	printf("Voici l'adresse de p %p \n", &p);

	polynome* p2 = creer_monome(3, 2);
	printf("Le coef de p2 est %f et le degré de p2 est %d \n", p2->coef, p2->degre);
	printf("Voici l'adresse de p %p \n", &p2);

	/*
	ajouter_monome (p,1,2);
	ajouter_monome (p,6,6);
	ajouter_monome (p,-6,6);
	ajouter_monome (p,-1,0);
	printf("\n---------\n p :");
	afficher_polynome(p);
	
	
	polynome* q = creer_polynome_constant(35);
	ajouter_monome (q,-1,2);
	ajouter_monome (q,3,1);
	printf("\n---------\n Q =");
	afficher_polynome(q);
	
	printf("\n---------\n Q(34) = %f ",evaluer_Horner(q,34));
	printf("\n---------\n Q(34) = %f (methode de Horner) ",evaluer_polynome(q,34));
	
	printf("\n---------\n");
	polynome* r=somme(p,q);
	printf("P+Q =");
	afficher_polynome(r);
	
	printf("\n---------\n");
	polynome* rc = copie(r);
	printf("copie P+Q =");
	afficher_polynome(rc);
	
	printf("\n---------\n");
	polynome* pp = produit(p,p);
	printf("P*P =");
	afficher_polynome(pp);
		
	printf("\n---------\n");
	polynome* p2 = puissance(p,3);
	printf("P^3 =");
	afficher_polynome(p2);	


	printf("\n---------\n");
	polynome* dq = derive(q);
	printf("Q'=");
	afficher_polynome(dq);
	
	printf("\n---------\n");
	polynome* comp = composition(q,p);
	printf("q rond p=");
	afficher_polynome(comp);
	
		
	printf("\n---------\n end\n");
	*/
}




int main(void){
	test();
}

