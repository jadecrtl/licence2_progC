#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int v;
    scanf ("%d", &v);
    int i=1;
    int j = 0;
    int total = 1;

    if (v == 0) {
        return 1;
    } else if (v < 0 || v >= 31) {
        return 0;
    }
    while (i<=v){
        total *= i;
        i++;
        j++;
        printf ("%d !",j);
        printf ("= %d\n",total);
    }

return (0);
}