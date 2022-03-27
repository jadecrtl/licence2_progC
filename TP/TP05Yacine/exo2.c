#include <stdio.h>
#include <stdlib.h>
#define print_ptr(a) printf("%p (%lu) = %d\n", a, (unsigned long) a, *a)

int i = 1;
int j = 2;

void f(int n){
    int i = 5;
    int j = 5;
    print_ptr(&i);
    print_ptr(&j);
    if(n > 0){
        f(n-1);
    }
}

int main(){
    int k = 0;
    int l = 0;
    int *ptr = malloc(sizeof(int));
    int *ptr2 = malloc(sizeof(int));
    print_ptr(&i);
    print_ptr(&j);
    print_ptr(&k);
    print_ptr(&l);
    f(10);
    print_ptr(ptr);
    print_ptr(ptr2);

}