#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct array {
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
};
typedef struct array array;

array* array_init(unsigned int cap) {
    array* a = malloc(sizeof(array));
    if (a == NULL)
        return NULL;
    a -> ptr = malloc (cap * sizeof(int));
    if (a -> ptr == NULL)
        return NULL;
    a -> capacite = cap;
    a -> taille = 0;
    return a;
}

void array_destroy(array *t) {
    if (t != NULL) {
        free(t -> ptr);
        free(t);
    }
}

int array_get(array *t, unsigned int index) {
    assert(t != NULL);
    assert(index >= 0 && index < t -> taille);
    return *(t -> ptr + index);
}

void array_set(array *t, unsigned int index, int valeur) {
    assert(t != NULL);
    assert(index >= 0 && index < t -> taille);
    *(t -> ptr + index) = valeur;
}

void array_append(array*t, int val) {
    assert(t != NULL);
    assert(t -> taille < t -> capacite);
    t -> ptr[t -> taille] = val;
    t -> taille++;
}

void array_print(array *t) {
    for (int i = 0; i < t -> taille; i++) {
        printf("%d \n", array_get(t, i));
    }
}

int array_search(array *t, int val) {
    assert(t != NULL);
    for (int i = 0; i < t -> taille; i++) {
        if (array_get(t, i) == val) {
            return i;
        }
    }
    return -9999;
}

array* array_init_from(int* mem, unsigned int len, unsigned int cap) {
    assert(cap >= len);
    array* res = array_init(cap);
    for (int i = 0; i < len; i++) {
        array_append(res, *mem);
    }
    return res;
}

void array_remove(array *t, unsigned int index) {
    for (int i = index; i < t -> taille - 1; i++) {
        array_set(t, i, array_get(t, i+1));
    }
    t ->taille--;
}

void permute(array* t, unsigned int index, int i) {
    printf("Je suis dans permute\n");
    int tmp = t -> ptr[index];
    t -> ptr[index] = t -> ptr[i];
    t -> ptr[i] = tmp;
}

void array_insert(array *t, unsigned int index, int valeur) {
    assert(t != NULL && index >= 0 && index <= t -> taille);
    if (t -> taille == t -> capacite) {
        printf("test de t -> taille == t -> capacite");
        t -> ptr = realloc(t -> ptr, t -> capacite * 2 * sizeof(int));
        if (t -> ptr == NULL) {
            perror("Erreur du realloc");
            exit(1);
        }
        t -> capacite *= 2;
    }
    if (index == t -> taille) {
        printf("test de index == t -> taille");
        array_append(t, valeur);
        return;
    }
    for (int i = index + 1; i < t-> taille; i++) {
        permute(t, index, i);
    }
    t -> ptr[t -> taille] = t -> ptr[index];
    t -> taille++;
    array_set(t, index, valeur);
}



int main() {
    array* tab = array_init(10);

    array_print(tab);//n'affiche rien et c'est normal

    array_append(tab, 1);
    array_append(tab, 2);
    array_append(tab, 3);
    array_append(tab, 4);
    array_append(tab, 5);
    array_print(tab);

    printf("La valeur à l'indice 0 est : %d \n",array_get(tab, 0));//affiche 1  
    printf("La valeur à l'indice 1 est : %d \n",array_get(tab, 1));//affiche 2  
    printf("La valeur à l'indice 2 est : %d \n",array_get(tab, 2));//affiche 3

    array_set(tab, 2, 6);

    printf("La valeur à l'indice 2 est maintenant : %d \n",array_get(tab, 2));//affiche 6 
    printf("L'indice de la valeur 4 est : %d \n", array_search(tab, 4));//affiche 3 
    printf("L'indice de la valeur 8 est : %d \n", array_search(tab, 8));//affiche -9999 

    int tmp = 5;
    array* tab2 = array_init_from(&tmp, 3, 20);
    array_print(tab2);

    printf("---------\n");

    array_remove(tab2, 2);
    array_print(tab2);

    printf("---------\n");
    printf("---------\n");
    printf("---------\n");

    array_print(tab);
    printf("---------\n");
    array_remove(tab, 0);
    printf("---------\n");
    array_print(tab);

    printf("---------\n");

    array* tab3 = array_init(10);

    array_append(tab3, 2);
    array_append(tab3, 4);
    array_append(tab3, 6);
    array_append(tab3, 8);
    array_append(tab3, 10);
    array_print(tab3);

    printf("----On va maintenant tester array_insert-----\n");

    array_insert(tab3, 2, 5);//entre 4 et 6 on veut mettre 5
    //array_print(tab3);

    //array_print(tab3);

    array_insert(tab3, 6, 11);//après 10 qui est le dernier élément du tableau on veut mettre 11
    array_print(tab3);

    array_insert(tab3, 90, 3);//on veut tester un index plus grand que le tableau

    return 0;
}