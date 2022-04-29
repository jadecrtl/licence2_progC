#include <stdio.h>

void incr( int n ){
  n = n+1;
}

int main(void){
  int k = 1;

  for( int i = 0; i < 10; i++ )
    incr( k );

  printf("k= %d\n", k);
}
