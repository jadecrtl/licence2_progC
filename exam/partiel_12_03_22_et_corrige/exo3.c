#include <stdio.h>

void add_mult( int a, int b, int *somme, int *produit ){
  *somme = a + b;
  *produit = a * b;
  return;
}
int main( void ){
  int k = 6; int l = 4;
  int s, m;
  add_mult( k, l, &s, &m );
  printf("somme = %d,  produit= %d\n", s, m);
}
