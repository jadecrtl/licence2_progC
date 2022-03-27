#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STACK_INITIAL_CAPACITY 1

typedef struct point{
    double x;
    double y;
} point;

typedef struct stack{
    int capacity;
    int length;
    point* buffer;
} stack;



void stack_print(stack* s){
    printf("Capacity: %d\n", s->capacity); 
    printf("Length: %d\n", s->length); 
    for (int i = 0; i < s->length; i++) {
        printf("[%d] %20f %20f\n", i, s->buffer[i].x, s->buffer[i].y); 
    }
}

stack *stack_new(){
    int c = STACK_INITIAL_CAPACITY;
    int l=0;
    point * b = (point *) malloc(c*sizeof(point));
    if(b==NULL) return NULL;
    stack * res=(stack*)malloc(sizeof(stack));
    if(res==NULL) return NULL;
    res->capacity=c;
    res->buffer=b;
    return res;
}

int stack_delete(stack *s, point p){
    if(s!=NULL){
        free(s->buffer);
        free(s);
    }
}

int stack_push(stack *s, point p){
    assert(s);
    if(s->length == s->capacity){
        s->capacity *= 2;
        s->buffer = realloc(s->buffer, s->capacity*sizeof(point));
        if(s->buffer == NULL){
            free(s);
            return -1;
        }
    }
    s->buffer[s->length] = p;
    s->length++;
    return 0;
}

int stack_pop(stack * s, point *p){
    assert(s);
    if(s->length == 0) return -1;
    s->length --;
    *p = s->buffer[s->length];
    if(4*s->length <= s->capacity){
        s->capacity /=2;
        s->buffer = realloc(s->buffer,s->capacity*sizeof(point));
        if(s->buffer == NULL){
            free(s);
            return -1;
        }
    }
    return 0;
}




int main(){
    stack *p=stack_new();
    stack_print(p);


    return 0;
}