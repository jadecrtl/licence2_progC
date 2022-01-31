#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int v;
    int n;
    int j;
    scanf ("%d", &n);
   // printf ("%d",v);
    for( int i = 1; i < n ; i++){
        j=0;
        v=i;
        while (v != 1){
            if(v % 2 == 0){
                v = v / 2;
            }
            else{
                v = v * 3;
                v++;
            }
            j++;
      //  printf (" %d",v);
        }

        printf ("%d : %d\n", i, j);
    }
    return (0);
}