#include <stdio.h>

#define N 27

void affichage(int t[], int taille) {
    printf("%d\n",taille);//affiche 8
    printf("%ld\n",sizeof(t[0]));//affiche 4
    printf("%ld\n",taille/sizeof(t[0]));//affiche 2        
    
}

int syracuse(int n) {
    int res = n;
    int vol = 0;
    while(res != 1 && res >= 1) {
        vol++;
        printf("%d ", res);
        if (res % 2 == 0) {
            res = res / 2;
        }
        else {
            res = res * 3 + 1;
        }
    }
    printf("\n Le temps de vol est : %d \n", vol);
    return res;
}

int main() {
    int tab[] = {42, 17};
    affichage(tab, sizeof(tab));
    printf("Syracuse : %d \n", syracuse(N));
    return 0;
}