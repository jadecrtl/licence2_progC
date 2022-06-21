#include <stdio.h>


int main(void) {
    union valeur {
        char op;
        double nbr_double;
        int nbr_int;
        char *var;
    };

    enum type_donnee{OPERATION, NOMBRE_DOUBLE, NOMBRE_INT, VARIABLE};

    struct  noeud{
        enum type_donnee t;
        union valeur val;    
    };
    struct  noeud n = {.t = NOMBRE_DOUBLE,
                        .val = {.nbr_double = 3.14}};
    printf("%f\n", n.val.nbr_double);//affiche 3.140000
    n.t = OPERATION;
    n.val.op = '+';
    printf("%c\n", n.val.op);//affiche +
    printf("%f\n", n.val.nbr_double);//affiche 3.140000
    return 0;   
}

