#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STACK_INITIAL_CAPACITY 1
typedef struct point { 
    double x;
    double y; 
} point;

typedef struct stack { 
    int capacity;
    int length; 
    point* buffer;
} stack;



void stack_print(stack* s) { 
    printf("Capacity: %d\n", s->capacity); 
    printf("Length: %d\n", s->length); 
    for (int i = 0; i < s->length; i++) {
        printf("[%d] %20f %20f\n", i, s->buffer[i].x, s->buffer[i].y); 
    }
}

stack *stack_new(){
    int cap=STACK_INITIAL_CAPACITY;
    stack *s=malloc(cap*sizeof(stack));
    if( s == NULL) return NULL;
    s->buffer=malloc(sizeof(point));
    if(s == NULL) return NULL;
    s->capacity=cap;
    s->length=0;
    return s;
}

void stack_delete(stack *s){
    assert(s != NULL);
    free(s->buffer);
    free(s);
}

int stack_push(stack *s, point p){
    assert(s != NULL);
    if(s->length == s->capacity){
        s->capacity *= 2;
        s->buffer=realloc(s->buffer,s->capacity*sizeof(point));
        if(s->buffer == NULL){
            free(s->buffer);
            return -1;
        }
    }
    *(s->buffer+(s->length)) = p;
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

    stack *s=stack_new();
    stack_print(s);
    point p={.x=7,.y=8};
    point p1={.x=4.750,.y=20.212};
    point p2={.x=212,.y=-221};
    point p3={.x=2.212,.y=78.130};
    stack_push(s,p);
    stack_push(s,p1);
    stack_push(s,p2);
    stack_push(s,p3);
    stack_print(s);


    return 0;
}
