#include <stdio.h>
#define SUP 45

void crible(int n){
    int tab[n];
    int size = sizeof(tab)/sizeof(tab[0]);
    for (int i = 0; i < size; i++){
        tab[i] = 0;
    }
    
    for (int i = 2; i <= size; i++){
        for (int j = i+1; j <= size; j++){
            if(j%i == 0){
                tab[j] = 1;
            }
        }
        if(tab[i] == 0){
            printf("%d ",i);
        }
    }
    printf("\n");
}

int main(){
    crible(SUP);
}