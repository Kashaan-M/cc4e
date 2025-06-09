/*
Count blanks and new lines.
This will be provided as input to your program: Copy

But soft what light through yonder window breaks
It is the east and Juliet is the sun
Arise fair sun and kill the envious moon
Who is already sick and pale with grief


Output from your program:

29 4

*/
#include <stdio.h>
int main() /* count new lines in input */
{
    int c, nl, blanks;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
  		else if(c == ' ') ++blanks;
    printf("%d %d\n", blanks, nl);
}