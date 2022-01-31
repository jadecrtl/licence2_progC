#include <stdio.h>


int sommePui3() {
    int n = 0;
    scanf("%d", &n);
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += i*i*i;
    }
    return tmp;
}

int moyenne() {
    int n = 0;
    scanf("%d", &n);
    double res = 0;
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    res = res / n;
    return res;
}

int fact (int n) {
    int res = 1;
    if (n <= 0) {
        return res;
    }
    else {
        for (int i = 1; i <= n; i++) {
            res *= i;
            printf("%d! = %d\n", i, res);
        }
        return res;
    }
}


int main() {
    int a = sommePui3();
    printf("puissance 3 : %d \n", a);

    double b = moyenne();
    printf("moyenne : %f \n", b);

    int c = fact(-6);
    printf("Doit afficher 1 : %d \n", c);

    int d = fact(0);
    printf("Doit afficher 1 : %d \n", d);

    int e = fact(5);
    printf("Doit afficher 120 : %d \n", e);

    int f;
    scanf("%d", &f);
    int g = fact(f);
    printf("Doit afficher 120 en manuel si je tape 5: %d \n", g);


    return 0;
}
