#include <stdio.h>
#define NBR 5

/*void print_tab(int t[], int start, int end){
    for (int i = start; i < end; i++){
        printf("%p : %d \n",&t[i], t[i]);
    }
}*/

void print_tab(int *pstart, int *pend){
    while(pstart < pend){
        printf("%p : %d \n", pstart, *pstart);
        pstart++;
    }
    
}

int main(){
    int t[NBR];
    t[0] = 6;
    t[1] = 1;
    t[2] = 5;
    t[3] = 6;
    t[4] = 8;

    //print_tab(t,2,5);
    print_tab(&t[0],&t[4]);
}