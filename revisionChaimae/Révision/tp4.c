#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

 struct array {
  int *ptr;
  unsigned int capacite;
  unsigned int taille;
};
typedef struct array array;

array* array_init(unsigned int cap){
    array *p=malloc(sizeof(array));
    if(p == NULL) return NULL;
    p->ptr=malloc(cap*sizeof(int));
    if(p == NULL) return NULL;
    p->capacite=cap;
    p->taille=0;
    return p;
}

void array_destroy(array *t){
    if(t != NULL){
        free(t->ptr);
        free(t);
    }
}

int array_get(array *t, unsigned int index){
    assert(t!=NULL);
    assert(t->taille >= index && index >= 0);
    return *(t->ptr+index);
}

void array_set(array *t, unsigned int index, int valeur){
    assert(t != NULL);
    assert(t->taille >= index && index >= 0);
    *(t->ptr+index)=valeur;
}

void array_append(array*t, int val){
    assert(t != NULL);
    assert(t->taille < t->capacite);
    *(t->ptr+(t->taille))=val;
    t->taille++;
}

int array_search(array *t, int val){
    assert(t != NULL);
    for(int i=0; i<t->taille;i++){
        if(t->ptr[i] == val) return i;
    }
    return -1;
}

void array_print(array *t){
    printf("Capacite: %d\n", t->capacite); 
    printf("Taille: %d\n", t->taille); 
    for (int i = 0; i < t->taille; i++) {
        printf("[%d] %d\n", i, t->ptr[i]); 
    }
}

array* array_init_from(int* mem, unsigned int len, unsigned int cap){
    assert(len >= 0);
    assert(cap != NULL);
    assert(cap > len);
    array *a=array_init(cap);
    if(a == NULL) return NULL;
    for(int i=0;i<len;i++){
        a->ptr[i]=mem[i];
    }
    a->taille=len;
    return a;
}

void array_remove(array *t, unsigned int index){
    assert(index>=0);
    assert(t != NULL);
    int *m;
    for(int i=0;i<t->taille;i++){

    }
}

/*void array_insert(array *t, unsigned int index, int valeur){
    assert(index>=0);
    assert(t != NULL);
    for(int i=0; i<t->taille;i++){

    }
}*/

int main(){

    array *s=array_init(5);
    //array_print(s);
    array_append(s,1);
    array_append(s,2);
    array_append(s,3);
    array_append(s,4);
    array_append(s,5);
    array_print(s);
    printf("array_search(s,3)=%d\n",array_search(s,3));
    int *mem;
    mem=malloc(sizeof(int));
    mem[0]=1;
    mem[1]=2;
    mem[2]=3;
    array *a=array_init_from(mem,3,5);
    array_print(a);

    

    return 0;
}