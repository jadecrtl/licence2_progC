#include <stdio.h>
#define NBR 5

int nbr_occ(int nbr, int t[], int v){
    int cpt = 0;
    for (int i = 0; i < nbr; i++){
        if(t[i] == v){
            cpt++;
        }
    }
    return cpt;
}

void nbr_occ_op(int nbr, int t[], int v, int *pnv){
    int cpt = 0;
    for (int i = 0; i < nbr; i++){
        if(t[i] == v){
            cpt++;
        }
    }
    *pnv = cpt;
}

void min_max_op(int nbr, int t[], int *pmin, int *pmax){
    int min = t[0], max = t[0];
    for (int i = 1; i < nbr; i++){
        if(t[i] > max){
            max = t[i];
        } else if (t[i] < min){
            min = t[i];
        } 
    }
    *pmin = min;
    *pmax = max;
}

int main(){
    int t[NBR];
    int v = 4;
    int max = 100, min = -9;
    t[0] = 6;
    t[1] = 1;
    t[2] = 5;
    t[3] = 6;
    t[4] = 8;

    printf("%d \n",nbr_occ(NBR,t,2));
    printf("%d \n",nbr_occ(NBR,t,6));
    printf("%d \n",nbr_occ(NBR,t,8));

    printf("avant : %d \n",v);
    nbr_occ_op(NBR,t,6,&v);
    printf("après : %d \n",v);

    printf("min avant : %d \n",min);
    printf("max avant : %d \n",max);
    min_max_op(NBR,t,&min,&max);
    printf("min après : %d \n",min);
    printf("max après : %d \n",max);
}