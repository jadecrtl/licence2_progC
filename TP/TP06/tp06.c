#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//exo 1 :
char* dupliquer(const char* s) {
    assert(s != NULL);
    size_t l = strlen(s);
    char * res = malloc(sizeof(char) * (l+1));
    assert(res);
    memmove(res, s, (l+1)*sizeof(char));
    return res;
}

int supe(char c1, char c2) {
    if (c1 >= 97) {
        c1 -= 32;
    }
    if (c2 >= 97) {
        c2 -= 32;
    }
    if (c1 > c2) {
        return 1;
    }
    else if (c1 < c2) {
        return -1;
    }
    return 0;
}

int ordrealpha(const char* s1, const char* s2) {
    char * t1, *t2;
    int test;
    for (t1 = (char*) s1, t2 = (char*) s2; (*t1 != '\0') && (*t2 != '\0'); t1++, t2++) {
        test = supe(*t1, *t2);
        if (test == -1) {
            return -1;
        }
        else if (test == 1) {
            return 1;
        }
    }
    if (*t2 == '\0') {
        if (*t1 == '\0') {
            return 0;
        }
        return 1;
    }
    return -1;
}

char * multiplier (const char *s, unsigned int n) {
    assert(s != NULL);
    size_t l = strlen(s);
    char * res = malloc(sizeof(char) * (l*n+1));
    assert(res);
    for(int i = 0; i < n; i++) {
        memmove(res + i * l, s, l * sizeof(char));
    }
    res[l*n] = '\0';
    return res;
}

//exo 3:

typedef struct {
    size_t indice;
    size_t len;
} mutation;

//exo 3 question 3 :
mutation longest(const char* s , const char* t) {
    assert(strlen(s) == strlen(t));
    mutation m = {.indice = 0, .len = 0};
    mutation d = m;
    size_t l = strlen(s);
    for(int j = 0; j < l; j += d.indice + d.len) {
        //d = diff(s + j, t + j); faire la question 2 de l'exo 3 pour que cette ligne marche
        if (d.len == 0) break;
        if (d.len > m.len) {
            m.indice = d.indice;
            m.len = d.len;
        }
    }
    return m;
}

int nbr_words(const char* s) {
    int res = 0;
    int isword = 0;
    char *t1 = (char*) s;
    while (*t1 != '\0') {
        if (*t1 == ' ' && isword == 1) {
            isword = 0;
            res++;
        }
        if (isalpha(*t1)) {
            isword = 1;
        }
        *t1++;
    }
    if (isword == 1) {
        res++;
    }
    return res;
}


int main(int argc, char **argv) {
    /*int s = 0;
    for(int i = 1; i < argc; i++) {
        s += atoi(argv[i]);
    }
    printf("%s a calculé %d\n", argv[0], s);
*/
    //exo2 question 1 :
    //printf("%s ordrealpha %d\n", argv[0], ordrealpha(argv[1], argv[2]));
    //exo2 question 2 :
    //printf("multiplier %s\n", multiplier(argv[1], atoi(argv[2])));
    //exo3 question 1 :
    printf("Nbr words de %s : %d\n", argv[1], nbr_words(argv[1]));
    return 0;
}