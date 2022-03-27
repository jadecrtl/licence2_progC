#include <stdio.h>
#define NBR 5

int occ(int nbr, int t[], int v){
    for (int i = 0; i < nbr; i++){
        if(t[i] == v){
            return i;
        }
    }
    return -1;
}

int *occ_ptr(int nbr, int t[], int v){
    for (int i = 0; i < nbr; i++){
        if(t[i] == v){
            return &t[i];
        }
    }
    return NULL;
}

int main(){
    int t[NBR];
    t[0] = 2;
    t[1] = 4;
    t[2] = 5;
    t[3] = 1;
    t[4] = 2;

    printf("%d \n",occ(NBR,t,2));
    printf("%d \n",occ(NBR,t,5));
    printf("%d \n",*occ_ptr(NBR,t,5));
    printf("%d \n",*occ_ptr(NBR,t,2));
}