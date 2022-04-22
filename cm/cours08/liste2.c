#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

/******************
 * listes doublement chainees avec tete
 ******************************************/

typedef struct elem_liste elem_liste;
typedef  elem_liste *liste;
struct elem_liste{
  liste suivant;
  liste precedent;
  double val;
};




liste LD_creer_liste(void){
  liste l = malloc(sizeof(elem_liste));
  if( l == NULL ){
    return NULL;
  }
  l->suivant = l->precedent = l;
  l->val = NAN;
  return l;
}

bool LD_liste_vide( liste l ){
  return l==l->suivant;
}

/* le nombre d'elements */
unsigned int LD_nb_elem(liste l){
  unsigned int i;
  liste c;
  for(c = l->suivant, i=0; c != l; c = c->suivant, i++)
    ;   /* end for */
  return i; 
}

/* LD_ieme(liste l, int i) retourne le pointeur vers 
 * i-ieme element de la liste.
 * Les positions sont indexees a partir de 0.
 * Pour parcourir depuis la fin de laa liste fair i < 0.
 * i == -1 : le dernioer élément
 * i == -2 : avant dernier élément etc.
 */
liste LD_ieme(liste l, int i){
  liste c = NULL;

  if( LD_liste_vide( l ) )
    return NULL;
  
  if( i >= 0 ){
    for( c = l->suivant ;   i > 0 && c->suivant != l; c = c->suivant, i--)
      ;   /* end for */
    
    if( i > 0 ){
      return NULL;
    }
    return c;
  }


  if( i < 0 ){
    for( c = l ;   i < 0 && c->precedent != l; c = c->precedent, i++)
      ;   /* end for */
    
    if( i < 0 ){
      return NULL;
    }
    return c;
  }

  return c;
  
}


static liste LD_insert_between( liste a, liste b, double d){
  assert(a->suivant == b && b->precedent == a);
  liste nouveau = malloc(sizeof(struct elem_liste));
  if(nouveau == NULL)
    return NULL;
  nouveau->val = d;
  a->suivant = b->precedent = nouveau;
  nouveau->precedent = a;
  nouveau->suivant = b;
  return nouveau;
}



/* Ajouter un nouveau element juste apres 
 * l'element pointe par p.
 * v la valeur du nouveau element.
 * Retourne le pointeur vers le nouveau element ou NULL
 * si la fonction echoue.
*/
liste LD_ajouter_apres(liste p, double v){ 
  assert(p != NULL);

  return LD_insert_between(p, p->suivant, v);
}


liste LD_ajouter_avant(liste p, double v){ 
  assert(p != NULL);
  return LD_insert_between(p->precedent, p, v);
}



/* Ajouter un element a la ieme position.
 * Retourne le pointeur vers element ajouté  ou NULL 
 * si la fonction echoue.
 */
liste LD_ajouter_ieme(liste l, int i, double v){
  assert( l != NULL);
  liste cur;
  
  if( i >= 0 ){
    for( cur = l; i > 0  && cur->suivant != l; cur = cur->suivant, i--)
      ;
    if( i > 0 )
      return NULL;
    return LD_insert_between(cur, cur->suivant,v);
  }
  
  if( i < 0 ){
    for( cur = l; i < -1 && cur->precedent != l; cur=cur->precedent, i++)
      ;
    if( i < -1 )
      return NULL;
    return LD_insert_between( cur->precedent, cur, v);
  }
  return NULL;
}

/* supprimer élément pointé par l*/
double LD_supprimer( liste l ){
  if( l->suivant == l ){
    free(l);
    return INFINITY;
  }
  liste prec = l->precedent;
  liste suiv = l->suivant ;
  prec->suivant = suiv;
  suiv->precedent= prec;
  double d = l->val;
  free(l);
  return d;
}
  


/* afficher tous les elements de la liste */
void LD_afficher(liste l){
  liste c = l->suivant ;
  if(c == l){
    return;
  }
  printf("%.2f", c->val);
  for( c = c->suivant  ; c != l; c = c->suivant) {
    printf(", %.2f", c->val);
  }
  printf("\n");
}

int main(void){
  liste l = LD_creer_liste();
  for(int i = 0; i<5; i++){
    LD_ajouter_ieme(l, i, i);
  }
  LD_afficher(l);
  
  for(int i = -1; i > -5; i--){
    LD_ajouter_ieme(l, i, i);
  }

  LD_afficher(l);

  LD_supprimer( LD_ieme(l,0) );
  LD_afficher(l);
  
  LD_supprimer( LD_ieme(l,-1) );
  LD_afficher(l);

  
  LD_supprimer( LD_ieme(l, 2) );
  LD_afficher(l);

  LD_supprimer( LD_ieme(l, -2) );
  LD_afficher(l);
  
  
}
