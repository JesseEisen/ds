
//
// stack.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void 
_stack_push(stack_t *s, stack_t *sn) {
    assert(s != NULL  && sn != NULL);

    sn->next = s->next;
    s->next = sn;
}


stack_t *
_stack_pop(stack_t *s) {
    stack_t *ret = NULL;

    if(s != NULL) {
        ret = s->next;
        s->next = (ret->next == NULL? NULL: ret->next);
    }

    return ret;
}


void 
_stack_destory(stack_t *s, stack_extra_free f) {
    stack_t *ps = NULL;

    while(s  && s->next) {
        ps       = s->next;
        s->next  = ps->next;
        ps->next = NULL;
        if(f != NULL)  f(ps);
    }
}
