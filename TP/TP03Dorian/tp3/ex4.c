#include <stdio.h>
#include <stdlib.h>
void print_tab (int t[], int start, int end)
{
     for(int i = 0; i < end - 1; i++)
    {
        printf("%p :",&t[i]);
        printf("%d\n",t[i]);
        
    }
}
int main()
{
    int tab[4]={4,3,5,8};
    print_tab(&tab[1],1,4);
   
}