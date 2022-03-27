#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct array {
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
};
typedef struct array array;

array* array_init(unsigned int cap){
    array* a = malloc(sizeof(a));
    if( a == NULL){
        return NULL;
    }
    int *n = malloc(sizeof(cap));
    if( n == NULL){
        return NULL;
    }
    a -> ptr = n;
    a -> taille = 0;
    a -> capacite = cap;

    return a;
}

void array_destroy(array *t){
    free(t -> ptr);
    free(t);
}

int array_get(array *t, unsigned int index){
    assert(0 <= index && index < t -> taille);
    return t -> ptr[index];
}

void array_set(array *t, unsigned int index, int valeur){
    assert(0 <= index && index < t -> taille);
    t -> ptr[index] = valeur;
}

void array_append(array* t, int val){
    assert(t -> taille < t -> capacite);
    t -> ptr[t->taille] = val;
    t -> taille++;
}

void array_print(array* t){
    for(int i = 0; i < t->taille; i++){
        printf("%d ",array_get(t,i));
    }
    printf("\n");
}

int array_search(array* t, int val){
    for(int i = 0; i < t->taille; i++){
        if(array_get(t,i) == val){
            return i;
        }
    }
    return -1;
}

array* array_init_from(int* mem, unsigned int len, unsigned int cap){
    assert(cap > len);
    array* a = malloc(sizeof(a));
    if(a == NULL){
        return NULL;
    }
    int* tab = malloc(sizeof(cap));
    for (int i = 0; i < len; i++){
        tab[i] = mem[i];
    }
    a -> ptr = tab;
    a -> taille = len;
    a -> capacite = cap;
    
    return a;
}

void array_remove(array *t, unsigned int index){
    if(index >= t->taille){
        return ;
    }
    for(int i = index; i < t -> taille-1; i++){
        array_set(t,i,array_get(t,i+1));
    }
    t->ptr[t->taille-1] = 0;
    t -> taille--;
}

void array_insert(array *t, unsigned int index, int valeur){
    assert(t->taille >= index);
    if(t->taille == t->capacite){
        t->ptr = realloc(t->ptr, sizeof(t->capacite*2));
        t->capacite *= 2;
        t->taille++;
        for(int i = t->taille-1; i > index; i--){
            array_set(t,i, array_get(t,i-1));
        }
        t->ptr[index] = valeur;
    }else{
        if(t->taille == index){
            t->ptr[index] = valeur;
            t->taille++;
        }else{
            t->taille++;
            for(int i = t->taille-1; i > index; i--){
                array_set(t,i, array_get(t,i-1));
            }
            t->ptr[index] = valeur;
        }
    }
}

int main(){
    array* a = array_init(8);
    int tab[3] = {5,2,3};
    array_append(a, 60);
    array_append(a, 40);
    array_append(a, 27);
    array_append(a, 8);
    array_set(a,1,86);
    array_print(a);

    array* b = array_init_from(tab, 3, 5);

    /*printf("%d \n",array_search(a,27));
    printf("%d \n",array_search(a,5));
    printf("%d \n",array_search(a,86));*/

    array_append(b, 56);
    array_print(b);
    array_remove(b,2);
    array_print(b);
    array_insert(b,2,15);
    array_print(b);
    array_insert(b,4,14);
    array_print(b);
    array_insert(b,0,11);
    array_print(b);
}