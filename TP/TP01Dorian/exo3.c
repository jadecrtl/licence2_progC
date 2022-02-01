#include <stdio.h>
#define N 27

void syracuse(int n){
    int cpt = 0;
    int sauv = 0;
    for(int i = 1; i <= n;i++){
        sauv = i;
        while(sauv != 1){
            if(sauv % 2 == 0){
                sauv /= 2;
            } else {
                sauv = 3*sauv+1;
            }
            //printf("%d ",n);
            cpt++;
        }
        printf("\n%d = %d\n",i,cpt);
        cpt = 0;
    }
}

int main(){
    syracuse(N);
}