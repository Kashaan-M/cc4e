struct HashMapEntry {
    char *key; /* public */
    int value; /* public */
    struct HashMapEntry *__prev;
    struct HashMapEntry *__next;
};

struct HashMapIter {
    /*
    HashMap Iterator Requirements
    1- Must move through all the buckets
    2- Must skip empty buckets
    */
    int __bucket;
    struct HashMap *__map;
    struct HashMapEntry *__current;
    struct HashMapEntry* (*next)(struct HashMapIter *self);
    void (*del)(struct HashMapIter *self);
};

struct HashMap {
    int __buckets;
    /* Private Attributes */
    struct HashMapEntry *__heads[8];
    struct HashMapEntry *__tails[8];
    int __count;
/* Public methods */
void (*put)(struct HashMap * self,char * key, int value);
int (*get)(struct HashMap * self,char * key, int def);
int (*size)(struct HashMap * self);
void (*dump)(struct HashMap * self);
void (*del)(struct HashMap * self);
struct HashMapIter* (*iter)(struct HashMap *self);
};
/*
map->dump - in effect a toString() except we print the contents of the
Map to stdout.

self - The pointer to the instance of this class.
*/
void __HashMap_dump(struct HashMap * self)
{
    int i;
    struct HashMapEntry * cur;
    printf("Object HashMap@%p count=%d buckets=%d\n",self, self->__count, self->__buckets);
    for(i = 0 ; i < self->__buckets; i++) {
        for(cur= self->__heads[i]; cur != NULL; cur = cur->__next) {
            printf("%s=%d [%d]\n", cur->key, cur->value, i);
        }
    }
}
/*
__HashMap_find is a private method which is used by map->get() and map->put()
*/
struct HashMapEntry* __HashMap_find(struct HashMap* self, char *key, int bucket)
{
    struct HashMapEntry *cur;
    if ( self == NULL || key == NULL ) return NULL;
    for(cur = self->__heads[bucket]; cur != NULL ; cur = cur->__next ) {
        if(strcmp(key, cur->key) == 0 ) return cur;
    }
    return NULL;
}
/*
map->get - locate and return the value for the corresponding key or a
default value.
self - the pointer to the instance of this class.
key - a character pointer to the key value.
def - A default value to return if the key is not in the map.

Returns an integer
Example call:

int set = map->get(map,"s", 42);
This method takes inspiration from the python code
value = map.get("key", 42)
*/
int __HashMap_get(struct HashMap * self,char * key, int def)
{
    int bucket = getBucket(key, self->__buckets);
    struct HashMapEntry * curval = __HashMap_find(self, key, bucket);
    if(curval == NULL) return def;
    return (curval->value);
}
/*
map->put - Add or update an entry in the map.

self - The pointer to the instance of this class.
key - A character pointer to the key value.
value - The value to be stored with the associated key.

if the key is not in the Map, an entry is added. If there is
already an entry in the Map for the key, the value is updated.

Sample call:
map->put(map, "x", 42)
This method takes inpiration from the python code
map["key"] = value
*/
void __HashMap_put(struct HashMap * self,char * key, int value)
{
    int bucket;
    struct HashMapEntry *old, *new;
    if(key == NULL) return;

    char * new_key = (char *)malloc(strlen(key)+1);

    bucket = getBucket(key, self->__buckets);
    old = __HashMap_find(self, key, bucket);
    if(old != NULL) {
        old->value = value;
        return;
    }
    /* not found - time to insert */
    new = malloc(sizeof(*new));
    strcpy(new_key, key);
    new->key = new_key;
    new->value = value;
    new->__next = NULL;
    new->__prev = self->__tails[bucket];

    if(self->__heads[bucket] == NULL) self->__heads[bucket] = new;
    if(self->__tails[bucket] != NULL) self->__tails[bucket]->__next = new;
    self->__tails[bucket] = new;

    self->__count++;
}
/*
map->size - return number of items in the map.
*/
int __HashMap_size(struct HashMap* self)
{
    return (self->__count);
}
/*
__MapIter_next - Advance the iterator forwards or backwards and
return the next item

self - the pointer to the instance of this class.

returns NULL when there are no more entries.

This is inspired by the following python code.
item = next(iterator, None)
*/
struct HashMapEntry *__HashMapIter_next(struct HashMapIter *self)
{
    struct HashMapEntry *retval;
    /*
    if we are at the end of a chain and there are still more buckets
    scan for a bucket that is not NULL
    */
    while(self->__current == NULL) {
        self->__bucket++;
        if(self->__bucket >= self->__map->__buckets) return NULL;
        self->__current = self->__map->__heads[self->__bucket];
    }
    retval = self->__current;
    if(self->__current != NULL) self->__current = self->__current->__next;
    return retval;
}
/*
Destructor for MapIter
*/
void __HashMapIter_del(struct HashMapIter *self) {
    free((void *)self);
}
/*
__Map_iter - Constructor for MapIter, create an iterator from the head of HashMap
self - the pointer to the instance of this class

returns NULL when there are no entries in the HashMap

This is inspired by the following python code that
creates an iterator from a dictionary.
x = {'a':1, 'b':2, 'c':3}
it = iter(x)
*/
struct HashMapIter* __HashMap_iter(struct HashMap *map) {
    struct HashMapIter *iter = malloc(sizeof(*iter));
    iter->__map = map;
    iter->__bucket = 0;
    iter->__current = map->__heads[iter->__bucket];
    iter->next = &__HashMapIter_next;
    iter->del = &__HashMapIter_del;
    return (iter);
}
/*
Destructor for the Map class

Loops through and frees all the keys and entries in the map. The values
are integers so there is no need to free them.
*/
void __HashMap_del(struct HashMap * self)
{
    struct HashMapEntry * cur, * next;
    cur = self->__heads[0];
    while(cur) {
        free(cur->key);
        /* value is just part of the struct */
        next = cur->__next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* Constructor */
struct HashMap * HashMap_new() {
    struct HashMap * p = malloc(sizeof(*p));

    p->__buckets = 8;
    for(int i = 0; i < p->__buckets; i++) {
    p->__heads[i] = NULL;
    p->__tails[i] = NULL;
    }
    p->__count = 0;

    p->put = &__HashMap_put;
    p->get = &__HashMap_get;
    p->size = &__HashMap_size;
    p->dump = &__HashMap_dump;
    p->del = &__HashMap_del;
    p->iter = &__HashMap_iter;
    return p;
}
/*
hashing function
*/
int getBucket(char *str, int buckets)
{
    unsigned int hash = 123456;
    printf("Hashing %s\n", str);
    if(str == NULL) return 0;
    for(;*str; str++) {
        hash = (hash << 3) ^ *str;
        printf("%c 0x%08x %d\n", *str, hash, hash % buckets);
    }
    return (hash % buckets);
}