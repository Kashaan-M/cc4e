/*
Copyright (c) Kashaan Mahmood 
An Implementation of a key-value pair Map class using a doubly linked list.
We use iterator abstraction so that we can have the same functionality inside
main() for 
a linked list based map
a hash based map
a tree based map
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "33_map_class_using_iterator.h"

int main(void) {
    struct MapEntry *cur;
    struct Map *map = Map_new();
    struct MapIter *iter;

    printf("Map Test\n");
    map->put(map, "z", 0);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "a", 4);
    map->dump(map);

    printf("z=%d\n", map->get(map, "z", 42));
    printf("c=%d\n", map->get(map, "c", 42));

    printf("\nIterate\n");
    iter = map->iter(map);
    while(1) {
        cur = iter->next(iter);
        if(cur == NULL) break;
        printf("%s=%d\n", cur->key, cur->value);
    }
    iter->del(iter);
    map->del(map);
}