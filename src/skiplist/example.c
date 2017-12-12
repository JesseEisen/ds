
//
// example.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

int main() {
    int arr[1000];
    int value;
    
    srand(time(NULL));

    sl_list *sl = sl_create_list();
    int i;

    for(i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    for(i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
        sl_insert(sl,arr[i],arr[i]);

    sl_search(sl, arr[4], &value);
    printf("\nSearch %d\n", value);
    
    sl_del_node(sl,arr[4]);
    printf("\ndelete node %d\n", arr[4]);
    
    sl_free(sl);

    return 0;
}
