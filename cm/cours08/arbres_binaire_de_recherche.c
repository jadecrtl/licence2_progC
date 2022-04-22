#include <stdio.h>
#include <stdlib.h>


typedef struct sommet sommet;
typedef sommet *arbre;
typedef int info;

struct sommet{
  arbre fg;
  arbre fd;
  info val;
};

/* abr_supprimmer_racine supprime la racine s de l'arbre 
 * binaire de recherche.
 * 
 * Le resultat : l'arbre apres la suppression s 
 */
arbre abr_supprimer_racine( arbre a ){
  arbre c;
  
  if( a -> fg == NULL ){
    c = a->fd;
    free( a );
    return c;
  }else if( a -> fd == NULL ){
    c = a ->fg;
    free(a);
    return c;
  }
  
  arbre  parent_c;

  /* chercher le plus grand dans le sous-arbre gauche de la racine */
  for( c = a -> fg, parent_c = NULL ; c->fd != NULL; parent_c = c, c=c->fd )
    ; /* boucle vide */

  /* parent_c == NULL quand  le plus grand élément dans le sous-arbre gauche
   * est la racine de sous-arbre gauche. Cela arrive uniquement quand 
   * racine->fg->fd == NULL 
   */
  if( parent_c == NULL ){ 
    c->fd = a->fg;
    free( a );
    return c;
  }

  a->val = c->val; /* transférer la valeur la plus grande à gauche dans la racine */
  parent_c -> fd = c->fg; /* parent de c obtient un nouveau enfant droit*/
  free( c );
  return a;
}


arbre abr_supprimer_valeur(arbre a, info v){
  arbre c = a, parent_c = NULL;
  while( c != NULL ){
    if(c->val < v){
      parent_c = c;
      c = c->fd;
    }
    else if(c->val > v){
      parent_c = c;
      c = c -> fg;
    }
    else break;
  }

  if( c == NULL )
    return a; /* rien à supprimer */
  
  if( c -> val == v ){
    if( parent_c == NULL )
      return abr_supprimer_racine(c) ;
    else if( parent_c->fg == c ){
      parent_c -> fg = abr_supprimer_racine(c) ;
    } else if( parent_c -> fd == c ){
      parent_c -> fd = abr_supprimer_racine(c) ;
    }
  }

  return a;
}


arbre abr_creer_node( info v ){
  arbre s = malloc(sizeof(sommet));
  if(s == NULL)
    return NULL;
  s->fg = s->fd = NULL;
  s->val = v;
  return s;
}


arbre abr_ajouter(arbre r, info v){

  arbre new = abr_creer_node( v );
  if( new == NULL ){
    return NULL;
  }
  if( r == NULL )
    return new;
  /* recherche de la position pour inserer le nouveau node */
  arbre c = r, p = NULL;
  while( c != NULL ){
    p = c;
    if( v < c->val ){ 
      c = c->fg;
    }
    else{
      c = c->fd;
    }
  }

  if( v < p->val ){
    p->fg = new;
  }
  else{
    p->fd = new;
  }
  return r;
} 

void abr_afficher(arbre a){
  if( a == NULL )
    return;
  abr_afficher(a->fg);
  printf("%d  ", a->val );
  abr_afficher(a->fd);

}

int main(void){

  int t[]={5, -9, 11, -5, 0, 6, 12, 11, 8, -33, 45};
  unsigned int s = sizeof(t)/sizeof(t[0]);
  arbre a = NULL;
  for(unsigned int i=0; i < s; i++){
    a = abr_ajouter(a, t[i]);
  }


  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,11);
  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,45);
  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,6);
  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,-33);
  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,-9);
  abr_afficher(a);
  printf("\n");
  a = abr_supprimer_valeur(a,5);
  abr_afficher(a);
  printf("\n");


  return 0;
}
