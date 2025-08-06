struct lnode {
    char *text;
    struct lnode *next;
};
struct pylist {
    struct lnode *head;
    struct lnode *tail;
    int count;
};

/* print(lst) */
void pylist_print(struct pylist* self)
{
    /* About 10 lines of code 
       The output should match Python's
       list output

       ['Hello world', 'Catch phrase']

	Use printf cleverly, *not* string
	concatenation since this is C, not Python.
    */
    struct lnode * cur;
    printf("[");
    for(cur = self->head; cur != NULL; cur= cur->next) {
        if(cur->next == NULL) {
            printf("'%s'",cur->text);
        }
        else {
        printf("'%s',",cur->text);
        }
    }
    printf("]\n");
}

/* len(lst) */
int pylist_len(const struct pylist* self)
{
    /* One line of code */
    return self->count;
}

/* lst.append("Hello world") */
void pylist_append(struct pylist* self, char *str) {
    /* Review: Chapter 6 lectures and assignments */
    struct lnode * new = malloc(sizeof(*new));
    char * new_str = malloc(sizeof(str));
    strcpy(new_str,str);
    if(self->tail != NULL) self->tail->next = new;
    new->text = new_str;
    new->next = NULL;
    self->tail = new;

    if(self->head == NULL) self->head = new;
    self->count += 1;
}
/* lst.index("Hello world") - if not found -1 */
int pylist_index(struct pylist* self, char *str)
{
    /* Seven or so lines of code */
    int i = 0;
    struct lnode * cur;

    for(cur = self->head; cur != NULL; cur = cur->next,i++) {
        if(strcmp(cur->text, str) == 0) {
            return(i);
        }
    }
    return(-1);
}

/* Constructor */
/* lst = list() */
struct pylist * pylist_new() {
    struct pylist * p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return(p);
}
/* Destructor - del(lst) */
void pylist_del(struct pylist* self) {
    struct lnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}
