#include <stdio.h>
#include <stdlib.h>

int main(){
    int t1[3] = {1, 2, 3}, *pt1;
    int t2[] = {1, 2, 3}, *pt2;
    pt1 = t1+1;
    //t2 = pt2; fonctionne pas

    printf("%d == %d \n",*pt1,*pt2);

    int t3[3], *pt3;
    pt3 = malloc (5 * sizeof (int));
    pt3 = t3;

    //int t4[5] = malloc (5 * sizeof (int));

    //printf("%d \n",*pt3);

    int *pt4;
    pt4 = malloc(5 * sizeof(int));
    *pt4 = 10;
    *(pt4+1) = 20;
    *(pt4+12) = 30;

    pt4[2] = 11;
    pt4[5] = 22;
    pt4[10] = 33;

    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
    pt4 = pt4+1;
    printf("%d \n",*pt4);
}