/* Copyright (c) Kashaan Mahmood */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXVAL 1000

/* Attempted Implementation of Python-like string object 

x = str()
x = x + 'H'
x = x + "ello World."
x = "Thanks for the offer.";
*/

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
int main(){
    struct Pystr* p  = pystr_new();
    pystr_dump(p);
    pystr_append(p,'H');
    pystr_append(p,'e');
    pystr_append(p,'l');
    pystr_append(p,'l');
    pystr_append(p,'o');
    pystr_append(p,' ');
    pystr_append(p,'W');
    pystr_append(p,'o');
    pystr_append(p,'r');
    pystr_append(p,'l');
    pystr_append(p,'d');
    pystr_append(p,'.');
    pystr_dump(p);
    pystr_appends(p," Welcome to C programming");
    pystr_dump(p);
    pystr_assign(p,"Thanks. I am not sure I want to learn it...");
    pystr_dump(p);
}
