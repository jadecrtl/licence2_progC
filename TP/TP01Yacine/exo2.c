#include <stdio.h>

int somme(){
    int n = 0;
    int res = 0;

    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        res += i;
    }

    return res;
}

void question1(){
    int n = 0,res = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        res = res+i*i*i;
    }
    
    printf("%d\n",res);
}

int fact(int n){
    if (n <= 1){
        return 1;
    }
    return n*fact(n-1);
}

void fact2(int n){
    for(int i = 1; i <= n;i++){
        printf("%d! = %d\n",i,fact(i));
    }
}

void afficheTab(int* t[]){
     printf("sizeof(tab) = %d\n",sizeof(t));
    printf("sizeof(tab[0]) = %d\n",sizeof(t[0]));
    printf("sizeof(tab)/sizeof(tab[0]) = %d\n",sizeof(t)/sizeof(t[0]));
}

int main(){
    /*int n = 0;
    scanf("%d",&n);
    question1();
    printf("somme : %d\n",somme());
    printf("factoriel de %d : %d\n",n,fact(n));
    fact2(10);*/
    int tab[] = {42,17,75,84};
    printf("sizeof(tab) = %d\n",sizeof(tab));
    printf("sizeof(tab[0]) = %d\n",sizeof(tab[0]));
    printf("sizeof(tab)/sizeof(tab[0]) = %d\n",sizeof(tab)/sizeof(tab[0]));
    afficheTab(tab);
}