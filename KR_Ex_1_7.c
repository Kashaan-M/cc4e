/*
Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

This will be provided as input to your program: Copy

But soft  what light     through yonder window breaks
It is    the east and  Juliet is the sun
Arise fair sun   and kill the envious moon
Who  is  already  sick  and  pale  with  grief
*/
#include <stdio.h>
main() {
    int ch; /* Current Character */
  	int lch = 0; /* Last Character i.e. before current character */
    while ((ch = getchar()) != EOF) {
      	if(ch !=' ' | lch != ' ') { /* if current and last character are not spaces */ 
          /* print it */
          putchar(ch);
          /* remember the current for the next round */
          	lch = ch;
        }
    } 
}