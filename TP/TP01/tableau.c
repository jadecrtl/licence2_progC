#include <stdio.h>

#define N 27

void affichage(int t[], int taille) {
    printf("%d\n",taille);//affiche 8
    printf("%ld\n",sizeof(t[0]));//affiche 4
    printf("%ld\n",taille/sizeof(t[0]));//affiche 2        
    
}

void syracuse(int n) {
    int res = n;
    int vol = 0;
    int tmp = 0;
    for (int i = 1; i <= res; i++) {
        tmp = i;
        while(tmp != 1) {
            vol++;
            //printf("%d ", res);
            if (tmp % 2 == 0) {
                tmp = tmp / 2;
            }
            else {
                tmp = tmp * 3 + 1;
            }
        }
        printf("\n%d = %d\n",i, vol);
        vol = 0;
    }
    //printf("\n Le temps de vol est %d : %d \n",n, vol);
    //return res;
}

int main() {
    int tab[] = {42, 17};
    affichage(tab, sizeof(tab));
    //printf("Syracuse : %d \n", syracuse(N));
    syracuse(N);
    return 0;
}