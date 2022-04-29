#include <stdio.h>
typedef struct{
  int a; int b;
} toto;

toto enigme( toto x ){
  toto y ;
  y.a = x.a + x.b;    y.b = x.a - x.b;
  
  x.a = -x.a;         x.b = -x.b;
  return y;
}

int main( void ){
  toto e;
  e.a=1; e.b = -9;

  toto d = enigme(e);
  printf( "e.a = %d e.b = %d  d.a = %d d.b = %d\n", e.a, e.b, d.a, d.b);
}
  
  
  
    
