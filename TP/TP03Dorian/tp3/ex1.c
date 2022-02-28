#include <stdio.h>
#include <stdlib.h>


void swap (int *p , int * q )
{
    int tmp = *p;
    *p = *q;
    *q=tmp;
   
}
int main()
{   int tab[2]={0,1};
    for(int i = 0; i<2;i++)
    {
        printf("%d\n",tab[i]);
    }
    swap(&tab[0],&tab[1]);
    for(int i = 0; i<2;i++)
    {
        printf("%d\n",tab[i]);
    }
int x, y;
x = 5;
y = 6;
printf ("(avant) x : %d, y : %d\n", x, y); // => (avant) 5 6
swap (&x, &y);
printf ("(apres) x : %d, y : %d\n", x, y); // => (apres) 6 5
}