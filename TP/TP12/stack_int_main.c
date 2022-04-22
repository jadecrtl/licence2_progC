#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define TABLEN 3

void stack_int_print(stack s)
{
    printf("Capacity: %ld\n", s.capacity);
    printf("Length: %ld\n", s.length);
    for (size_t i = 0; i < s.length; i++) {
            printf("[%ld] = %d\n", i, ((int*)s.buffer)[i]);
    }
}

int main()
{
        stack s;
        int tab[] = {1, 2, 3};

        if(stack_init(&s, sizeof(int)) == NULL) {
                perror("stack_init");
                return EXIT_FAILURE;
        }
        for(size_t i = 0; i < TABLEN; i++) {
                stack_push(&s, &tab[i]);
        }
        stack_int_print(s);

        stack_cleanup(s);
        return EXIT_SUCCESS;
}
