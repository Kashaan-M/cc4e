#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1000

struct lnode {
    char *text;
    struct lnode *next;
};

int main() {
    // we need a head and a tail node. Both of which point to NULL at beginning.
    struct lnode *head = NULL;
    struct lnode *tail = NULL;
    struct lnode *current;
    char line[MAXLEN];

    printf("sizeof struct lnode=%ld\n",sizeof(head));
    
    while(fgets(line,MAXLEN,stdin) != NULL) {
        printf("sizeof(line)=%ld\n",sizeof(line));
        char *save = (char *) malloc(strlen(line)+1);
        printf("sizeof(save)=%ld\n",sizeof(save));
        strcpy(save,line);

        struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
        printf("sizeof(new)=%ld\n",sizeof(new));
        
        if(tail != NULL) tail->next = new;
        new->text = save;
        new->next = NULL;
        tail = new;

        if(head == NULL) head = new;

        printf("head=%p, tail=%p\n",head,tail);
        printf("sizeof(head)=%ld,sizeof(head->text)=%ld, sizeof(tail)=%ld\n",sizeof(head),sizeof(head->text),sizeof(tail));
    }

    for(current = head; current != NULL; current=current->next) {
        printf("%s",current->text);
    }
}