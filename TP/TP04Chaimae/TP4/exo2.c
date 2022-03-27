#include <stdio.h>
#include <assert.h>

struct array{
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
};
typedef struct array array;

array* array_init(unsigned int cap){
    array* a=malloc(sizeof(array));
    if(a==NULL) return NULL;
    a -> ptr=malloc(cap*sizeof(int));
    if(a==NULL) return NULL;
    a -> capacite=cap;
    a -> taille=0;
    return a;
}

void array_destroy(array *t){
    if(t!=NULL){
    free(t->ptr);
    free(t);
    }
}

int array_get(array *t,unsigned int index){
    assert(t!=NULL);
    assert(index >= 0 && index<t->taille);
    return(t->ptr+index);
}

void array_set(array *t, unsigned int index, int valeur){
    assert(t != NULL);
    assert(index>=0 && index<t->taille);
    *(t->ptr+index)=valeur;
}

void append(array *t, int val){
    assert(t!=NULL);
    assert(t->taille < t->capacite);
    t->ptr[t->taille]=val;
    t->taille++;
}

int array_search(array *t,int val){
    assert(t!=NULL);
    for(int i=0;i<t->taille;i++)
        if(t->ptr[i]==val) return i;
    return -1;
}

array* array_init_from(int *mem, unsigned int len, unsigned int cap){
    assert(len <=0);
    assert(mem!=NULL);
    array * res=array_init(cap);
    for(int i=0;i<len;i++)
        res->ptr[i]=mem[i];
    res->taille=len;
    return res;
}

void array_remove(array *t, unsigned int index, int valeur){
    assert(t!=NULL); 
    for(int i=0; i<t->taille;i++){
        if(t->ptr[i]==valeur){
            
        }
    }   
}

void array_insert(array *t, unsigned int index){

}


int main(){

    return 0;
}

