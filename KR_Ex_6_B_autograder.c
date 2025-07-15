/*
Linked List

You will extend the previous assignment with list_add() and list_find() 
and add a function called list_delete() that will find and remove the node
containing the integer value if it is in the list. 

Expected output from your program:

Dump:
  10
  20
  30

Dump:
  20
  30

Dump:
  20

Dump:
  20
  40
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct lnode {
    int value;
    struct lnode *next;
};

struct list {
  struct lnode *head;
  struct lnode *tail;
};

void list_add(lst, value)
    struct list *lst;
    int value;
{
    /* Append the value to the end of the linked list. */
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    if(lst->tail != NULL) lst->tail->next = new;
    new->value = value;
    new->next = NULL;
    lst->tail = new;

    if(lst->head == NULL) lst->head = new;
}

struct lnode * list_find(lst, value)
    struct list *lst;
    int value;
{
    /* return NULL if value not in lst, else return struct lnode with value */
    struct lnode *cur;
    for(cur = lst->head; cur != NULL; cur = cur->next) {
        if(cur->value == value)
            return cur;
    }
    return NULL;
}

void list_remove(lst, value)
    struct list *lst;
    int value;
{
    /* Remove the value from the linked list. */
     struct lnode *cur = (struct lnode *)malloc(sizeof(struct lnode));
     struct lnode *prev = (struct lnode *)malloc(sizeof(struct lnode));
     prev = NULL;

    for(cur = lst->head; cur != NULL;cur = cur->next) {
        if(cur->value == value) {
            if(value == lst->head->value) { // if value is first item in lst 
                lst->head = cur->next;
                free(cur);
                break;
            }
            else if(cur->next == NULL) { // if value is last item in lst
            prev->next = NULL;
            lst->tail = prev;
            free(cur);
            break;
            }
            else { // if value is an item in the middle of lst somewhere
                prev->next = cur->next;
                free(cur);
                break;
            }
        }
        prev = cur;
    }
}

int main()
{
    void list_add();
    void list_dump();
    struct lnode * list_find();

    struct list mylist;
    struct lnode * mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_add(&mylist, 40);
    list_add(&mylist, 50);
    list_dump(&mylist);

    list_remove(&mylist, 42);

    list_remove(&mylist, 10);
    list_dump(&mylist);

    list_remove(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 50);
    list_dump(&mylist);

    list_add(&mylist, 60);
    list_dump(&mylist);

}

void list_dump(lst)
    struct list *lst;
{
    struct lnode *cur;
    printf("\nDump:\n");
    for(cur=lst->head; cur != NULL; cur=cur->next) {
        printf("  %d\n", cur->value);
    }
}