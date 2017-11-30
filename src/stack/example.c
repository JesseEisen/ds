
//
// example.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
    stack_t   s;
    int       num;
}mynum;

int 
main(void) {
    mynum num_stack;
    mynum *p; 
    
    int  i;

    STACK_INIT(num_stack.s);

    for(i = 0; i < 10; i++) {
        p = malloc(sizeof(mynum));
        p->num = i;
    
        STACK_PUSH(num_stack.s, p);
    }

    printf("\n");
    p = (mynum *)STACK_TOP(num_stack.s);
    printf("   Top of stack: %d\n\n", p->num);

    for(i = 0; i < 10; i++) {
        if(!STACK_EMPTY(num_stack.s)) {
            p = (mynum *)STACK_POP(num_stack.s);
            printf("   Pop: %d\n", p->num);
            free(p);
        }
    }

    printf("\n");
    return 0;
}
