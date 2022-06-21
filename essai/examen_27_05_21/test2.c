#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct point point;
struct point {
    double x;
    double y;
};

typedef struct node node;
struct node {
    node *next;
    point p;
};

double distance(const point *p, const point *q) {
    /*
    int calc = ((p->x - q->x) * (p->x - q->x) + (p->y - q->y) * (p->y - q->y));
    double d = sqrt(calc);
    return d;
    */
   double res = 0;
   double a = p->x - q->x;
   a *= a;
   double b = p->y - q->y;
   b *= b;
   double tmp = a + b;
   res = sqrt(tmp);
   return res;
}

node *getNewNode(int px, int py) {
    node *next = malloc(sizeof(node));
    assert(next != NULL);
    next->p = (point) {.x = px, .y = py};
    next->next = NULL;

    return next;
}

double perimetre(node *lpoint) {
    double res = 0;
    node *cur = NULL;
    for (res = 0, cur = lpoint; cur->next != NULL; cur = cur->next) {
        double tmp = distance(&(cur->p), &(cur->next->p));
        res += tmp;
    }
    res += distance(&(lpoint->p), &(cur->p));
    return res;
}


int main() {
    point *a = malloc(sizeof(point));
    if (a == NULL) {
        perror("malloc failed\n");
        exit(1);
    }
    a->x = 10;
    a->y = 10;
    point *b = malloc(sizeof(point));
    if (b == NULL) {
        perror("malloc failed\n");
        exit(1);
    }
    b->x = 12;
    b->y = 12;
    double res = distance(a, b);
    printf("res = %lf\n", res);
    free(a);
    free(b);

    node *lp = getNewNode(1, 1);
    assert(lp != NULL);
    lp->next = getNewNode(2, 2);
    lp->next->next = getNewNode(5, 5);

    double p = perimetre(lp);
    printf("perim =  %lf\n", p);

    free(lp->next->next);
    free(lp->next);
    free(lp);


    return 0;
}