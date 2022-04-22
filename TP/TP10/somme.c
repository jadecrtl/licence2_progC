#include <stdio.h>

void read_eval_print(FILE *f_in, FILE *f_out);

int main(int argc, char *argv[]) {
    return 0;
}

void read_eval_print(FILE *f_in, FILE *f_out) {
    int aux = 0, res = 0;
    while(fscanf (f_in, "%d", &aux) == 1) {
        res += aux;
    }
    fprint(f_out, "%d", res);
}