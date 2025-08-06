/* 
See "Map_Class_Implementing_Encapsulation_in_C.png"
Note members and methods with __ in their name are private
*/
struct MapEntry {
    char *key; /* public */
    int value; /* public */
    struct MapEntry *__prev;
    struct MapEntry *__next;
};

struct Map {
    /* Private Attributes */
    struct MapEntry *__head;
    struct MapEntry *__tail;
    int __count;
/* Public methods */
void (*put)(struct Map * self,char * key, int value);
int (*get)(struct Map * self,char * key, int def);
int (*size)(struct Map * self);
void (*dump)(struct Map * self);
void (*del)(struct Map * self);
};
/*
map->dump - in effect a toString() except we print the contents of the
Map to stdout.

self - The pointer to the instance of this class.
*/
void __Map_dump(struct Map * self)
{
    struct MapEntry * cur;
    printf("Object Map count=%d\n", self->__count);
    for(cur= self->__head; cur != NULL; cur = cur->__next) {
        printf("%s=%d\n", cur->key, cur->value);
    }
}
/*
__Map_find is a private method which is used by map->get() and map->put()
*/
struct MapEntry* __Map_find(struct Map* self, char *key)
{
    struct MapEntry *cur;
    if ( self == NULL || key == NULL ) return NULL;
    for(cur = self->__head; cur != NULL ; cur = cur->__next ) {
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
int __Map_get(struct Map * self,char * key, int def)
{
    struct MapEntry * curval = __Map_find(self, key);
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
void __Map_put(struct Map * self,char * key, int value)
{
    struct MapEntry *old, *new;
    if(key == NULL) return;

    char * new_key = (char *)malloc(strlen(key)+1);

    old = __Map_find(self, key);
    if(old != NULL) {
        old->value = value;
        return;
    }
    new = malloc(sizeof(*new));
    strcpy(new_key, key);
    new->key = new_key;
    new->value = value;
    new->__next = NULL;
    new->__prev = self->__tail;

    if(self->__head == NULL) self->__head = new;
    if(self->__tail != NULL) self->__tail->__next = new;
    self->__tail = new;

    self->__count++;
}
/*
map->size - return number of items in the map.
*/
int __Map_size(struct Map* self)
{
    return self->__count;
}

/*
Destructor for the Map class

Loops through and frees all the keys and entries in the map. The values
are integers so there is no need to free them.
*/
void __Map_del(struct Map * self)
{
    struct MapEntry * cur, * next;
    cur = self->__head;
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
struct Map * Map_new() {
    struct Map * p = malloc(sizeof(*p));

    p->__head = NULL;
    p->__tail = NULL;
    p->__count = 0;

    p->put = &__Map_put;
    p->get = &__Map_get;
    p->size = &__Map_size;
    p->dump = &__Map_dump;
    p->del = &__Map_del;
    return p;
}