#include <stdio.h>

void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main(){
    int x, y;
    int tab[2];
    tab[0] = 2;
    tab[1] = 4;
    x = 5;
    y = 6;
    printf("(avant) x : %d, y : %d\n", x, y); // => (avant) 5 6
    swap(&x, &y);
    printf("(apres) x : %d, y : %d\n", x, y); // => (apres) 6 5
    printf("(avant) x : %d, y : %d\n", tab[0], tab[1]); // => (avant) 2 4
    swap(&tab[0], &tab[1]);
    printf("(apres) x : %d, y : %d\n", tab[0], tab[1]); // => (apres) 4 2
}