#include <stdlib.h>
#include <string.h>

typedef struct{
  unsigned int len;
  int *val;
} vector;

vector vect_creer( unsigned int n, int c[]){
  vector v;
  v.len = n;
  v.val = malloc( sizeof( int ) * n );
  if( v.val == NULL )
    abort();

  memmove(v.val, c, sizeof( int ) * n );
  return v;
}

vector vect_concat( vector a, vector b){

  vector c;
  c.len = a.len+b.len;

  c.val = malloc( c.len * sizeof( int ));

  if( c.val == NULL )
    abort();

  memmove( c.val, a.val , a.len * sizeof( int ));
  memmove( c.val + a.len , b.val , b.len * sizeof( int ));
  return c;  
}

int main(){

  int x[] = { 1,2,3,4};
  int y[] = { 5,6,7,8};


  vector a = vect_creer( 4, x);
  vector b = vect_creer( 4, y);
  vector c = vect_concat( a,b);
}
