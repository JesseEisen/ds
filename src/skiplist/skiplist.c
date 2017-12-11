
//
// skiplist.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "skiplist.h"


sl_list * sl_create_list(){
    sl_list *sl = malloc(sizeof(struct skip_list));
    if(sl == NULL)
        return NULL;

    sl->level = 0;

    sl_node *header = malloc(sizeof(struct node));
    header->next = malloc(sizeof(struct node *) * MAXLEVEL);
    header->key = 0;
    header->value = 0;

    sl->head = header;

    int i;

    for(i = 0; i< MAXLEVEL; i++){
        header->next[i] = NULL;
    }

    srand(time(NULL));

    return sl;
}

int randomLevel(){
    int level = 1;
    while(rand() % 2)
        level++;

    level=(MAXLEVEL > level) ? level: MAXLEVEL;

    return level;
}

sl_node *sl_create_node(int level,int key, int value){
    sl_node *p = malloc(sizeof(struct node));
    if(p == NULL)
        return NULL;
    p->next = malloc(sizeof(struct node *) * level);
    if(p->next == NULL)
        return NULL;
    p->value = value;
    p->key  =key;

    return p;

}


int sl_insert(sl_list *sl, int key, int value){
    sl_node *update[MAXLEVEL];
    sl_node *q = NULL, *p = sl->head;
    int i = sl->level -1;

    for(; i>= 0; i--){
        while((q=p->next[i]) && q->key < key)
            p = q;
        update[i] = p; //find a first suitable place to insert
    }

    if(q && q->key == key){ //key has exsist
        q->value = value;
        return 1;
    }

    /*generate a random level*/
    int level = randomLevel();

    if(level > sl->level){
        for(i = sl->level; i<level; i++){
            update[i] = sl->head;
        }
        sl->level = level;
    }

    q = sl_create_node(level, key, value);
    if(q == NULL)
        return 0;

    for(i = level-1; i>=0; i--){
        q->next[i] = update[i]->next[i];
        update[i]->next[i] = q;
    }

    return 1;

}

int sl_search(sl_list *sl, int key, int *val){
    sl_node *q, *p = sl->head;

    q= NULL;
    int i = sl->level -1;

    for(; i >= 0; i--){
        while((q=p->next[i]) && q->key < key){
            p = q;
        }

        if(q && key == q->key) {
            *val = q->value;
            return 0;
        }
    }

    return -1;
}

int sl_del_node(sl_list *sl, int key){
    sl_node *update[MAXLEVEL];
    sl_node *q=NULL, *p= sl->head;
    int i = sl->level - 1;

    for(; i >= 0; i--){
        while((q=p->next[i]) && q->key < key){
            p = q;
        }

        update[i] = p;
    }

    if(!q || (q && q->key != key))
        return 0;

    for(i = sl->level -1; i>=0; --i){
        if(update[i]->next[i] == q){
            update[i]->next[i] = q->next[i];
            if(sl->head->next[i] == NULL)
                sl->level--;
        }
    }

    free(q);
    q=NULL;
    return 1;
}

void sl_free(sl_list *sl){
    if(sl == NULL)
        return;

    sl_node *q = sl->head;
    sl_node *next;

    while(q){
        next= q->next[0];
        free(q);
        q = next;
    }

    free(sl);
}

void sl_dump(sl_list *sl){
    int i;
    sl_node *head = sl->head;
    sl_node *p = NULL;

    for(i = sl->level-1; i >= 0; i--){
        p = head->next[i];
        printf("level %d: ", i);
        while(p != NULL){
            printf("%d  ",p->value);
            p = p->next[i];
        }
        printf("\n");
    }

}


