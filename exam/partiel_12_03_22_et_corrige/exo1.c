#include <stdio.h>
#include <string.h>
int main(void){
  int tab[]={ 2, 4, 5, 6, 7, 8, 9, 10, 11 };

  int *pt = &tab[ 7 ];
  int *pu = &tab[ 1 ]; 

  printf( "diff = %td\n",  pt - pu );
  printf( "valeurs = %d, %d\n",  *pu - 1, *(pu - 1));

  printf( "val = %d\n",  *(tab+2)+2 ); 

  int *p = &tab[4];

  int l = p[-2] ;
  printf( "l = %d\n", l);

  p[-3] = p[-3] + p[-1];

  *(p-1) = *(p+1) + *(p-1);

  for( int i=0; i < 9; i++)
    printf("[ %d ] = %d, ", i, tab[i]);
  return 0;
}


