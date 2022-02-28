#include <stdio.h>

int g(int n);

int f(int n){
    if(n == 1){
        return 2;
    }
    return 2*g(n-1);
}

int g(int n){
    if(n == 1){
        return 1;
    }
    return 3*f(n/2);
}

int main(){
    printf("%d \n",f(20));
}