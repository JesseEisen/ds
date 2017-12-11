
//
// skiplist.h
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#ifndef _SKIP_LIST_H_
#define _SKIP_LIST_H_

#define MAXLEVEL 7

typedef struct node {
    int key;
    int value;
    struct node **next;
}sl_node;

typedef struct skip_list {
    int     level;
    sl_node *head;
}sl_list;

sl_list*  sl_create_list();
void      sl_dump(sl_list *);
void      sl_free(sl_list *);
int       sl_insert(sl_list *, int, int);
int       sl_search(sl_list *, int, int*);
int       sl_del_node(sl_list *, int);


#endif
