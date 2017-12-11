
//
// example.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

int main(){
    int arr[] = {1,2,3,4,5,6,7,43,2,56,89,100};
    int value;

    sl_list *sl = sl_create_list();
    int i;

    for(i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
        sl_insert(sl,arr[i],arr[i]);

    sl_dump(sl);
    sl_search(sl, 56, &value);
    printf("\nSearch %d\n", value);
    
    sl_del_node(sl,56);
    printf("\ndelete node 56\n");
    if(sl_search(sl, 56, &value) == -1) {
        sl_dump(sl);
    }
    
    sl_free(sl);

    return 0;
}
