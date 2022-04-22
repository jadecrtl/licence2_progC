#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

/* lists simplement chainees avec tete 
 * la t�te c'est le premier �l�ment de la liste qui nee contient aucune valeur utile.
 *    */

struct elem{
  struct elem *suivant;
  double data;
};
typedef struct elem elem;
typedef elem *list;


/* creer list vide : liste vide contient juste un �l�ment, la t�te de la liste */

list list_create(){
  list tete = malloc( sizeof(elem));
  if(tete == NULL)
    return NULL;
  tete -> suivant = NULL;
  tete->data = 0;
  return tete;
}

/* inserer un nouveau elemen d apres l
   retourne le pointeur vers le nouveau �l�ment */

list list_insert_next( list l, double d ){
  elem *new = malloc( sizeof( elem ) );
  if( new == NULL )
    return NULL;

  new->data = d;
  new->suivant = l->suivant;
  l->suivant = new;
  return new;
}


/* list_remove_next(list l) supprime l'�l�ment qui se trouve juste 
 * apr�s l'�l�ment point� par l. 
 * S'il n'y a pas d'�l�ment apr�s l la fonction retourne sans rien faire.
 * Dans tous les autre cas elle retourne l.                                     */
list list_remove_next(list l){

  if(l == NULL || l->suivant == NULL)
    return l;
  
  list p=l->suivant;
  l->suivant = p->suivant;
  free(p);
  
  return l;
}




/********************************************************************************
 * ajouter_ieme ajoute un �l�ment avec la valeur d sur la position <<position>>
 * dans la liste l et retourne le pointeur vers le d�but de la liste.
 *
 * Les positions sont numerotees de fa�on suivante:
         
       __________       ___________       __________       ___________
      |          |     |           |     |          |     |           |
    0 |    1     |  1  |     2     |  2  |    3     |  3  |     4     | 4
      |          |     |           |     |          |     |           |
      ------------     -------------     ------------     -------------

 * c'est-�-dire la position 0 est avant le premier �l�lemnt, et, en g�n�ral
 * pour tout i>0, i-�me position se situe juste apr�s i'�me �l�ments de la liste.
 *******************************************************************************/

list list_insert_ieme(list l, double d, unsigned int  position){

  /* si position >0 alors  trouvez l'�l�ment u de la liste 
   * tel que l'insertion      
   * s'effectue juste avant u                                                       */
  
  while( position > 1 && l != NULL){
    position--;
    l = l -> suivant;
  }
  if(l == NULL)
    return NULL;

  return list_insert_next( l, d ) ;

}


/* supprime_ieme supprime i-�me �l�ment de la liste l.
 * la fonction  retourne le pointeur vers l'�l�ment qui pr�c�de
 * l'�l�m�nt supprim� ou NULL  
 * les �l�m�nts sont num�rot�s � partir de 0 */
list list_remove_ieme(list l, unsigned int i){

  while( i > 0 && l->suivant != NULL ){
    i--;
    l = l->suivant;
  }
  if( l->suivant == NULL )
    return NULL;
  
  return list_remove_next(l);
}


/* detruire la list */
void list_free(list l){
  while( l != NULL){
    list next = l->suivant;
    free(l);
    l=next;
  }
}


/* retourne ieme valeur stockee dans  la liste 
 * ou NaN not number)  s'il n'y a pas de i-eme element
 * on suppose que les �l�ments sont num�rot�s � partir de 0 (comme les indices d'un vecteur)
 */
double list_ieme(list l, unsigned int i){
  for( ; i>0 && l->suivant != NULL; i--, l=l->suivant )
    ;/* boucle vide */
  if( l->suivant == NULL )
    return NAN;
  else
    return l->suivant->data;
}

/* longueur retourne la longueur de la liste*/
int list_length(list l){
  unsigned int i;
  for( i=0, l=l->suivant ; l != NULL ; l=l->suivant, i++)
    ; /*boucle vide*/
  return i;
}

/* si l est une liste tri�e dans l'ordre croissant 
   inserer un nouveau element en respectant l'ordre            */
list list_insert_in_order(list l, double d){
  list precedent = l;
  list courant = l->suivant;

  while(courant != NULL && courant->data < d){
    precedent = courant;
    courant = courant->suivant;
  }

  return list_insert_next( precedent, d);
}


void list_print(list l){
  int i = 0;
  for( l = l->suivant; l != NULL; l=l->suivant)
    printf("element %d = %3.1f\n", ++i , l->data);
  printf("****************** fin de la liste *********************\n");
}

/*****
 * 
 *  compiler :
 *  gcc -Wall -pedantic liste_texte.c
 *  ex�cuter en passant comme param�tre de main les valeurs � mettre sur la liste :
 *  ./a.out � -55 98 -34 89 -11 -56 87 
 ****************************/
int main( int argc, char **argv ){

  list l = list_create();
  if( l==NULL )
    abort();

  for( int i=1; i < argc; i++){
    list_insert_in_order(l, atof( argv[i] ) );
  }

  list_print( l );

  list_remove_ieme(l , 0 );
  
  list_print( l );

  list_remove_ieme(l, 1);
  
  list_print( l );

  list_remove_ieme( l, list_length( l ) - 1 );

  list_print( l );
}
  
