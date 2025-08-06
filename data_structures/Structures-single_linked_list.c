#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// see Chapter_6_Structures7.png 

#define MAXLINE 1000

struct lnode {
    char *text;
    struct lnode *next;
};

int main()
{
/*When we start the list, head and tail both point to NULL */
  struct lnode *head = NULL;
  struct lnode *tail = NULL;
  struct lnode *current;
  char line[MAXLINE];

  while(fgets(line, MAXLINE, stdin) != NULL) {
      char *save = (char *) malloc(strlen(line)+1);
      strcpy(save, line);

      struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
      if ( tail != NULL ) tail->next = new;
      new->text = save;
      new->next = NULL;
      tail = new;

      if ( head == NULL ) head = new;
  }
    // print the list in forward order
  for (current = head; current != NULL; current = current->next ) {
      printf("%s", current->text);
  }

}