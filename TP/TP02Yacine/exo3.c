#include <stdio.h>
#include <assert.h>
#include <math.h>

struct fraction {
    long int num;
    long int den;
};

typedef struct fraction fraction;

struct point {
    fraction x;
    fraction y;
};

typedef struct point point;

fraction build(long int n, long int d){
    assert(d);
    fraction f;
    f.num = n;
    f.den = d;
    return f;
}

int eq_fraction(fraction f, fraction g){
    if(f.num*g.den == f.den*g.num){
        return 1;
    }
    return 0;
}

int is_int(fraction f){
    if(f.den == 1){
        return 1;
    }
    return 0;
}

fraction sum(fraction f, fraction g){
    fraction res;
    if(f.den != g.den){
        res.num = f.num*g.den+g.num*f.den;
        res.den = f.den*g.den;
    } else {
        res.num = f.num+g.num;
        res.den = f.den;
    }
    return res;
}

fraction sub(fraction f, fraction g){
    fraction res;
    if(f.den != g.den){
        res.num = f.num*g.den-g.num*f.den;
        res.den = f.den*g.den;
    } else {
        res.num = f.num-g.num;
        res.den = f.den;
    }
    return res;
}

fraction mul(fraction f, fraction g){
    return (fraction){f.num*g.num, f.den*g.den};
}

long abs(long x){
    if(x < 0){
        return -x;
    }
    return x;
}

long pgcd(long a,long b){
    long x = a;
    long y = b;
    long r = 0;
    while (y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

fraction reduce(fraction f){
    fraction res;
    long a = abs(f.num);
    long b = abs(f.den);
    if (f.num < 0 && f.den > 0 || f.num > 0 && f.den < 0){
        res.num = -(f.num/pgcd(a,b));
        res.den = f.den/pgcd(a,b);
    } else {
        res.num = f.num/pgcd(a,b);
        res.den = f.den/pgcd(a,b);
    }
    return res;
}

void affiche_fraction(fraction f){
    printf("%ld/%ld \n",f.num,f.den);
}

int eq_point(point p1, point p2){
    fraction x1, y1, x2, y2;
    x1 = reduce(p1.x);
    y1 = reduce(p1.y);
    x2 = reduce(p2.x);
    y2 = reduce(p2.y);
    if(eq_fraction(x1,x2) && eq_fraction(x2,y2)){
        return 1;
    }
    return 0;
}

double dist(point p1, point p2){
    double x1,x2;
    fraction f,g;

    f = sub(p2.x,p1.x);
    g = sub(p2.y,p1.y);

    x1 = (double)f.num/(double)f.den;
    x2 = (double)g.num/(double)g.den;

    return sqrt(pow(x1,2)+pow(x2,2));
}

int main(){
    fraction ex_fractions[7];
    ex_fractions[0] = build(1,1);
    ex_fractions[1] = build(1,2);
    ex_fractions[2] = build(2,4);
    ex_fractions[3] = build(-9,3);
    ex_fractions[4] = build(8,-20);
    ex_fractions[5] = build(-5,-1);
    ex_fractions[6] = build(1,-3);
    point a = {.x = ex_fractions[0], .y = ex_fractions[1]};
    point b = {.x = ex_fractions[0], ex_fractions[6]};

    affiche_fraction(ex_fractions[0]);
    affiche_fraction(sum(ex_fractions[1],ex_fractions[2]));
    affiche_fraction(sub(ex_fractions[0],ex_fractions[1]));
    affiche_fraction(mul(ex_fractions[3],ex_fractions[4]));
    affiche_fraction(reduce(ex_fractions[2]));

    printf("distance : %f \n",dist(a,b));
}