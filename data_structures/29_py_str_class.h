struct Pystr {
    int length;
    int alloc; /* the length of data */
    char *data;
};

/* Methods*/
/* len(x) */
int pystr_len(const struct Pystr* self)
{
    return self->length;
}
/* str(x) */
char *pystr_str(const struct Pystr* self)
{
    return self->data;
}
/* print(x) */
void pystr_dump(const struct Pystr* self)
{
    printf("Object length=%d alloc=%d data=%s\n",self->length, self->alloc,self->data);
}
/* x = x + 'H' */
void pystr_append(struct Pystr* self, char ch)
{    
    int i;
    /* if we don't have space for 1 character plus termination, allocate 10 more */
    if(self->length >= (self->alloc - 2)) {
            self->alloc = self->alloc + 10;
            self->data = (char *) realloc(self->data, self->alloc);
        }
    // printf("self->length=%d,self->alloc=%d,self->data=%s\n",self->length,self->alloc,self->data);
    for(i=0; i <= strlen(self->data); i++) {
        if(self->data[i] == '\0') {
                self->data[i] = ch;
                self->length = self->length + 1;
                self->data[i+1] = '\0';
                break;
        }
    }
}
/* x = x + "ello" */
void pystr_appends(struct Pystr* self, char *newdata)
{   
    int i = 0;
    while(i < strlen(newdata)) {
        pystr_append(self, newdata[i]);
        i++;
    }
}
/* x = "hello" */
void pystr_assign(struct Pystr* self, char *new)
{
    int i;
    self->length = 0;
    self->alloc = 10;
    self->data[0] = '\0';
    for(i=0; i < strlen(new); i++) {
        pystr_append(self,new[i]);
    }
}

/* constructor */
/* x = str() */
struct Pystr * pystr_new()
{
    struct Pystr *p = malloc(sizeof(*p));
    p->length = 0;
    p->alloc = 10;
    p->data = malloc(10);
    p->data[0] = '\0';
    return p;
}
/* destructor */
/* del x */
void pystr_del(const struct Pystr* self)
{
    free((void *)self->data); /* free string first */
    free((void *)self);
}