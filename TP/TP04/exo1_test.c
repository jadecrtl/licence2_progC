#include <stdio.h>

int main() {
    //int t[] = {1, 2, 3}, *pt;
    //t = pt; error : assignment to expression with array type

    int t[3], *pt;
    pt = malloc (5 * sizeof (int));
    pt = t;

    return 0;
}