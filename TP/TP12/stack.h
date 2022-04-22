#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct {
        size_t capacity;
        size_t length;
        size_t te; // la taille en octets d'un element de la liste
        void *buffer;
} stack;

stack *stack_init(stack *s, size_t te);

void stack_cleanup(stack s);

stack *stack_push(stack *s, void *el);

stack *stack_pop(stack *s, void *el);

stack *stack_clone(stack *s1, stack s2);

stack *stack_push_vect(stack *s, size_t len, void *vect);

stack *stack_pop_vect(stack *s, size_t *slen, size_t len, void *vect);

#endif
