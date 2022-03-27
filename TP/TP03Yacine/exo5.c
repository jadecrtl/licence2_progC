#include <stdio.h>
#define NBR 5

void sort(int t[], int start, int end){
    
    for(int j = end-1; j > 1; j--){
        for (int i = start; i < end; i++){
            if(t[i] > t[i+1]){
                int tmp = t[i];
                t[i] = t[i+1];
                t[i+1] = tmp;
            }
        }
    }
    
}

void sort_ptr(int *start, int *end){
    
    while(end-1 > start){
        while(start < end){
            if(*start > *(start+1)){
                int tmp = *start;
                *start = *(start+1);
                *(start+1) = tmp;
            }
            start++;
        }
        end--;
    }
    
}

int main(){
    int t[NBR];
    t[0] = 6;
    t[1] = 1;
    t[2] = 5;
    t[3] = 6;
    t[4] = 8;

    /*sort(t,0,5);

    for(int i = 0; i < NBR; i++){
        printf("%d ",t[i]);
    }
    printf("\n");*/

    sort_ptr(t, t+NBR);

    for(int i = 0; i < NBR; i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}