
//
// stack.h
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#ifndef _STACK_H_
#define _STACK_H_

typedef struct _stack {
    struct _stack *next;
}stack_t;

typedef void (*stack_extra_free) (stack_t *f);

stack_t * _stack_pop(stack_t *s);
void      _stack_push(stack_t *s, stack_t *sn);
void      _stack_destory(stack_t *s, stack_extra_free f);

#define STACK_INIT(s)       do { (s).next == NULL;} while(0)
#define STACK_EMPTY(s)      ((s).next == NULL)
#define STACK_TOP(s)        (s).next
#define STACK_POP(s)        _stack_pop(&(s))
#define STACK_PUSH(s, sn)   _stack_push(&(s), (stack_t *)sn)
#define STACK_DESTORY(s)    _stack_destory(&(s), ((stack_extra_free)free_fn))


#endif
