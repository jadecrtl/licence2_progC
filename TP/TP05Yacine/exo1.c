#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf(" Length: %d\n", s->length);
    for (int i = 0; i < s->length; i++) {
        printf("[%d] %20f %20f\n", i, s->buffer[i].x, s->buffer[i].y);
    }
}

stack *stack_new(){
    stack *s = malloc(sizeof(s));
    if(s == NULL){
        return NULL;
    }

    point *p = malloc(sizeof(STACK_INITIAL_CAPACITY));

    s -> buffer = p;
    s->capacity = STACK_INITIAL_CAPACITY;
    s->length = 0;

    return s;
}

void stack_delete(stack *s){
    free(s->buffer);
    free(s);
}

int stack_push(stack *s, point p){
    if(s->length == s->capacity){
        printf("%d\n",s->capacity);
        s->buffer = realloc(s->buffer, s->capacity*2);
        if(s->buffer == NULL){
            return -1;
        }
        s->capacity*=2;
    }
    s->buffer[s->length] = p;
    s->length++;
    return 0;
}

int stack_pop(stack *s, point *p){
    if(s->length == 0){
        return -1;
    }
    *p = s->buffer[s->length-1];
    s->length--;
    return 0;
}

stack *stack_clone(stack *s){
    stack *res = stack_new();
    memmove(res->buffer, s->buffer, s->capacity*sizeof(point));
    res->capacity = s->capacity;
    res->length = s->length;
    return res;
}

int stack_push_vect(stack *s, int len, point *vect){
    if(s->capacity < len){
        return -1;
    }
    memmove(s->buffer,vect,len*sizeof(point));
    s->length = len;
    if(s->buffer == NULL){
        return -1;
    }
    return 0;
}

stack_pop_vect(stack *s, int len, point *vect){
    if(s->length > len){
        return -1;
    }
    memmove(vect,s->buffer,len*sizeof(point));
    int i = 0;
    int res = s->length;
    while(i < s->length){
        stack_pop(s,vect);
        i++;
    }
    return res;
}

int main(){
    stack *s = stack_new();
    point p;
    p.x = 2;
    p.y = 0;
    point p2;
    p2.x = 4;
    p2.y = 1;
    point p4;
    p4.x = 7;
    p4.y = 7;
    point p3[2];
    p3[0] = p2;
    p3[1] = p4;
    stack_push(s,p);
    stack_print(s);
    stack_push(s,p2);
    stack_print(s);
    printf("%d\n",stack_pop(s,p3));
    stack_print(s);
    printf("%20f, %20f \n",(*p3).x,(*p3).y);

    stack *s2 = stack_clone(s);
    stack_delete(s);
    stack_print(s2);

    printf("=============\n");

    stack_push_vect(s2,2,p3);
    stack_print(s2);
    stack_pop_vect(s2,3,p3);
    stack_print(s2);
}