 
/**
 * Un polynome P sera représenté par une liste chainée avec les conventions suivantes :
 * Le premier maillon sera un maillon factice avec degre=-1 et coeff=0
 * Ensuite les maillons correspondent aux monomes de P triés par ordre décroissant de degré
 * A l'excpetion du premier maillon, aucun maillon ne devra avoir un coefficient nul
 * (Le polynome nul sera représenté par un polynome avec l'unique maillon factice initial)
 */

typedef struct polynome{
	double coef;
	int degre; 
	struct polynome *suiv;
} polynome;


/*cree le premier maillon factice et retourne son adresse*/
polynome* creer_polynome_vide();

/*cree un maillon de coefficient c et degre d*/
polynome* creer_monome(double c, int d);


/*libere tous les maillons du polynome a l'exception du maillon initial*/
void annuler(polynome* p);

/*retourne la valeur du polynome p evalué en x*/
double evaluer_polynome(polynome* p,double x);

/* affiche le polynome sous forme standard. Ex: 3X^4-5X^3+X+1 
 * A tester sur plusieurs polynomes
 * */
void afficher_polynome(polynome* p);


/*
 * ajoute un monome cX^d au polynome p.
 * Il faut preserver les conventions sur le polynome p
 * Attention notamment au cas ou un monome de meme degré existe deja dans p
 */ 
void ajouter_monome (polynome* p , double c, int d);

/* retourne une copie du polynome p */
polynome* copie(polynome* p);

/*retourne un nouveau polynome correspondant à la somme de p1 et p2*/
polynome* somme(polynome* p1, polynome* p2);

/*retourne un nouveau polynome correspondant à la difference de p1 et p2*/
polynome* soustraction(polynome* p1, polynome* p2);

/*retourne un nouveau polynome correspondant au produit de p1 et p2*/
polynome* produit(polynome* p1 ,polynome* p2);

/*retourne un nouveau polynome correspondant a p^n */
polynome* puissance(polynome* p, int n);

/*retourne un nouveau polynome correspondant au polynome dérivé p'*/
polynome* derive(polynome* p);






