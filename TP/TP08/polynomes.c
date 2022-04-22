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
	assert(nouvelElement != NULL);
	nouvelElement -> coef = 0;
	nouvelElement -> degre = -1;
	nouvelElement -> suiv = NULL;
	return nouvelElement;
}

/*cree un maillon de coefficient c et degre d*/
polynome* creer_monome(double c, int d) {
	if (c == 0) {
		printf("On ne peut pas créer un monome avec un coef à 0\n");
		return NULL;
	}
	if (d < 0) {
		printf("On ne peut pas créer un monome avec un degré négatif\n");
		return NULL;
	}
	polynome* nouveauMonome = malloc(sizeof(polynome));
	if(nouveauMonome == NULL) {
		perror("Le malloc pour la creation du monome n'a pas fonctionné\n");
		exit(1);
	}
	nouveauMonome -> coef = c;
	nouveauMonome -> degre = d;
	nouveauMonome -> suiv = NULL;
	return nouveauMonome;
}

/*retourne la valeur du polynome p evalué en x*/
double evaluer_polynome(polynome* p,double x) {
	double res = 0;
	polynome* aux = NULL;
	for (aux = p->suiv; aux != NULL; aux = aux->suiv) {
		res += pow(x, aux->degre) * aux->coef;
	}
	return res;
}

/*
 * ajoute un monome cX^d au polynome p.
 * Il faut preserver les conventions sur le polynome p
 * Attention notamment au cas ou un monome de meme degré existe deja dans p
 */ 
void ajouter_monome (polynome* p , double c, int d) {
	polynome* ajout = creer_monome(c,d);
	if (ajout == NULL) {
		return;
	}
	//On parcourt la liste en comparant le degré rencontré avec notre degré d
	polynome* pi = p;
	polynome* precedent = NULL;
	if (pi->suiv == NULL) {
		//printf("ajout dans le cas d'un polynome vide\n");
		pi->suiv = ajout;
		return;
	}
	//Si le polynome n'est pas vide alors on se place à la 1ere position où on trouve un vrai monome
	precedent = pi;
	pi = pi->suiv;
	while(pi->suiv != NULL) {
		//printf("****************coef %f\n", pi->coef);
		if (pi->degre == d) {
			//On va appliquer une somme algébrique de notre élément
			printf("degré égal\n");
			if (pi->coef + c == 0) {
				//On supprime le monome à la position pi
				precedent->suiv = pi->suiv;
				free(pi);
				return;
			}
			else {
				pi->coef = pi->coef + c;
				return;
			}
		}
		if (pi->degre < d) {
			//On va insérer notre monome ajout à la place de pi
			printf("degré inférieur existant %d et ajout %d\n", pi->degre, d);
			precedent->suiv = ajout;
			ajout->suiv = pi;			
			return;
		}
		precedent = pi;
		pi = pi->suiv;
	}
	//On est à la fin de la liste et comme on est pas sorti alors on insère notre élément à l'adresse pi->suiv
	if (pi->degre == d) {
		//On va appliquer une somme algébrique de notre élément
		printf("degré égal\n");
		if (pi->coef + c == 0) {
		//On supprime le monome à la position pi
			precedent->suiv = pi->suiv;
			free(pi);
			return;
		}
		else {
			pi->coef = pi->coef + c;
			return;
		}
	}
	printf("ajout en fin de liste\n");
	pi->suiv = ajout;
//	printf("monome ajouté de coef %3.1f et de degré %d\n", c, d);
}

/* affiche le polynome sous forme standard. Ex: 3X^4-5X^3+X+1 
 * A tester sur plusieurs polynomes
 * */
void afficher_polynome(polynome* p) {
	polynome* pi = p->suiv; //on saute le premier terme de coef 0 et degré -1
	if (pi == NULL) {
		printf("Le polynome est vide.\n");
		return;
	}
	while (pi->suiv != NULL) {
		printf("%3.1fX^%d", pi->coef, pi->degre);
		pi = pi->suiv;
		if(pi->coef > 0) {
			printf("+");
		}		
	}
	printf("%3.1fX^%d\n", pi->coef, pi->degre);	
}


/*libere tous les maillons du polynome a l'exception du maillon initial*/
void annuler(polynome* p) {
	polynome *aux1 = p -> suiv, *aux2;
	while(aux1 != NULL) {
		aux2 = aux1;
		aux1 = aux1 -> suiv;
		free(aux2);
	}
	p -> suiv = NULL;
}

/* retourne une copie du polynome p */
polynome* copie(polynome* p) {
	polynome* res = creer_polynome_vide();
	if (p == NULL) {
		return res;
	}
	for (polynome* aux = p->suiv; aux != NULL; aux = aux->suiv) {
		ajouter_monome(res, aux->coef, aux->degre);
	}
	return res;
}

/*retourne un nouveau polynome correspondant à la somme de p1 et p2*/
polynome* somme(polynome* p1, polynome* p2) {
	polynome* copieP1 = copie(p1);
	for (polynome* aux = p2->suiv; aux != NULL; aux = aux->suiv) {
		ajouter_monome(copieP1, aux->coef, aux->degre);
	}
	return copieP1;
}

/*retourne un nouveau polynome correspondant à la difference de p1 et p2*/
polynome* soustraction(polynome* p1, polynome* p2){
	
}

/*retourne un nouveau polynome correspondant au produit de p1 et p2*/
polynome* produit(polynome* p1 ,polynome* p2) {

}

/*retourne un nouveau polynome correspondant a p^n */
polynome* puissance(polynome* p, int n) {

}

/*retourne un nouveau polynome correspondant au polynome dérivé p'*/
polynome* derive(polynome* p) {

}


void test(){	
	printf("######## Test 1 pour créer polynome vide\n");
	polynome* p = creer_polynome_vide();
	printf("Le coef de p est %f et le degré de p est %d \n", p->coef, p->degre);
	printf("Voici l'adresse de p %p \n", &p);

//	printf("######## Test 1.1 pour tester qu'on ne peut pas créer un monome incorrect\n");
//	ajouter_monome(p,0,5);

//	printf("######## Test 2 pour créer un monome correct\n");
//	polynome* p2 = creer_monome(3, 2);
//	printf("Le coef de p2 est %f et le degré de p2 est %d \n", p2->coef, p2->degre);
//	printf("Voici l'adresse de p %p \n", &p2);

	printf("\n\n######## Test 1.2 pour ajouter un monome correct\n");
	ajouter_monome(p,-18,2);
	afficher_polynome(p);
	ajouter_monome(p,-5,1);
	afficher_polynome(p);
	ajouter_monome(p,26,3);
	afficher_polynome(p);
	ajouter_monome(p,4,5);
	afficher_polynome(p);
	ajouter_monome(p,7,4);
	afficher_polynome(p);
	ajouter_monome(p,-6,4);
	afficher_polynome(p);
	ajouter_monome(p,-1,4);
	afficher_polynome(p);
	ajouter_monome(p,5,1);
	afficher_polynome(p);
	ajouter_monome(p,-4,5);
	afficher_polynome(p);
	ajouter_monome(p,-26,3);
	afficher_polynome(p);
	ajouter_monome(p,18,2);
	afficher_polynome(p);

	printf("\n\n######## Test 1.2 pour évaluer un polynôme\n");
	polynome* p2 = creer_polynome_vide();
	ajouter_monome(p2,3,5);
	ajouter_monome(p2,2,2);
	ajouter_monome(p2,1.5,1);
	afficher_polynome(p2);
	double resultat = evaluer_polynome(p2,1);
	printf("\nLe resultat de l'evaluation pour le polynome p2 est : %f\n", resultat);

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

