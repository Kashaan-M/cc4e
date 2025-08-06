/*
Copyright (c) Kashaan Mahmood 
An Implementation of a key-value pair Map class using a doubly linked list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "32_map_class.h" /* header file containing structures and  functions definitions */

int main(void) {
    struct MapEntry *cur;
    struct Map * map = Map_new();

    printf("Testing Map Class\n");
    map->put(map, "x", 0);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "a", 4);
    map->dump(map);

    printf("z=%d\n", map->get(map, "z", 42));
    printf("c=%d\n", map->get(map, "c", 42));

    /* No iterator (for now) */
    map->del(map);
}