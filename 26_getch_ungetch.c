#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

char getch() /* get a (possibly pushed back) character */
{
return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (c) /* push character back on input */
int c;
{
if (bufp > BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}