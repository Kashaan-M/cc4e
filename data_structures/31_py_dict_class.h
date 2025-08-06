struct dnode {
    char * key;
    char * value;
    struct dnode * next;
};

struct pydict {
    struct dnode * head;
    struct dnode * tail;
    int count;
};

/* print(dct) */
/* {'z': 'W', 'y': 'B', 'c': 'C', 'a': 'D'} */
void pydict_print(struct pydict* self)
{
    struct dnode * cur = (struct dnode *)malloc(sizeof(struct dnode *));
    printf("{");
    for(cur=self->head; cur != NULL;cur = cur->next) {
        if(cur->next == NULL)
            printf("'%s': '%s'",cur->key, cur->value);
        else
            printf("'%s': '%s',",cur->key, cur->value);
    }
    printf("}\n");

}

int pydict_len(const struct pydict* self)
{
    return self->count;
}

/* find a node - used in get and put */
struct dnode* pydict_find(struct pydict* self, char *key)
{
    /* if node exists return node else return NULL */
    struct dnode * cur = (struct dnode *)malloc(sizeof(struct dnode *));
    
    for(cur = self->head; cur != NULL; cur = cur->next) {
        if(strcmp(cur->key, key) == 0)
            return(cur);
    }
    return NULL;
}

/* x.get(key) - Returns NULL if not found */
char* pydict_get(struct pydict* self, char *key)
{
    struct dnode * cur = (struct dnode *)malloc(sizeof(struct dnode *));
    if((cur = pydict_find(self,key)) == NULL)
        return NULL;
    else
        return(cur->value);
}

/* x[key] = value; Insert or replace the value associated with a key */
void pydict_put(struct pydict* self, char *key, char *value)
{
    struct dnode * new = (struct dnode *)malloc(sizeof(struct dnode *));
    /* cur is used for comparing if key already exists in self and replacing value*/
    struct dnode * cur = (struct dnode *)malloc(sizeof(struct dnode *));
    int key_exist = 0;
    int i;

    char * new_key = (char *)malloc(strlen(key)+1);
    char * new_value = (char *)malloc(strlen(value)+1);
    strcpy(new_key,key);
    strcpy(new_value,value);

    if((new = pydict_find(self,key)) != NULL) { /* replace value */
        new->value = new_value;
        return;
    }
    if(self->tail != NULL) self->tail->next = cur;
    cur->key = new_key;
    cur->value = new_value;
    cur->next = NULL;
    self->tail = cur;

    if(self->head == NULL) self->head = cur;
    (self->count)++;
}

/* Constructor - dct = dict() */
struct pydict * pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(dct) */
void pydict_del(struct pydict* self) {
    struct dnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}
