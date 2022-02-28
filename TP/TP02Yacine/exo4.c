#include <stdio.h>
#define N 5

void affiche_poly(int t[],int taille){
    if(t[0] != 0){
        printf("%d ",t[0]);
    }
    if(t[1] != 0){
        if(t[1] < 0){
            printf("- %dX ",abs(t[1]));
        } else {
            printf("+ %dX ",t[1]);
        }
    }
    if(t[2] != 0){
        if(t[2] < 0){
            printf("- %dX^2 ",abs(t[2]));
        } else {
            printf("+ %dX^2 ",t[2]);
        }
    }
    if(t[3] != 0){
        if(t[3] < 0){
            printf("- %dX^3 ",abs(t[3]));
        } else {
            printf("+ %dX^3 ",t[3]);
        }
    }
    if(t[4] != 0){
        if(t[4] < 0){
            printf("- %dX^4 ",abs(t[4]));
        } else {
            printf("+ %dX^4 ",t[4]);
        }
    }
    printf("\n");
}

void addition(int t1[],int t2[],int taille){
    int res[taille];
    for (int i = 0; i < taille; i++){
        res[i] = t1[i]+t2[i];
    }
    
    affiche_poly(res,N);
}

void multiplication(int t1[],int t2[],int taille){
    int res[taille];
    for (int i = 0; i < taille; i++){
        for (int k = 0; k < taille; k++){
            res[i+k] += t1[i]*t2[k];
        }
    }
    
    affiche_poly(res,N);
}

int main(){
    int t[N];
    int p[N];
    t[0] = 1;
    t[1] = 1;
    t[2] = 2;
    t[3] = 0;
    t[4] = 0;
    p[0] = 2;
    p[1] = 3;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    affiche_poly(t,N);
    addition(t,p,N);
}
