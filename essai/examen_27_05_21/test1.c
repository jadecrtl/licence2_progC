#include <stdio.h>
#include <string.h>
int main(void){
    char *s="abcdefghijkl";
    int i = 4 ;
    printf("A=%c\n", *(s+i) );
    printf("B=%c\n", s[++i] );
    char *c = s + 5;
    printf("longueur c=%zd\n", strlen(c) );
    printf("c decale = %c\n", c[-2] );
    int tab[]={1,2,3,4,5,6,7,8,9};
    int *pt = &tab[ 7 ];
    int *pu = &tab[ 1 ];
    printf( "diff = %td\n", pt - pu );
}