#include <stdio.h>
#include <string.h>
/*
Read set of lines and print the longest line.

The basic outline of this program
while(there is another line)
    if(it is longer than the previous longest)
    save it and its length
print longest line
*/
/*
Exercise 1-17. Write a function reverse(s) which reverses the character string s. 
            Use it to write a program which reverses its input a line at a time.
*/


int main() {
  char t[1000];
  char *copy();
  void reverse();
  copy("Hello world", t);
  printf("%s\n", t);
  reverse(t);
  printf("%s\n", t);
  reverse(copy("XY", t));
  printf("%s\n", t);
  reverse(copy("Even", t));
  printf("%s\n", t);
  reverse(copy("Odd", t));
  printf("%s\n", t);
  reverse(copy("civic", t));
  printf("%s\n", t);
}

/* copy s1 to s2; assume s2 big enough */
char *copy(s1, s2)
char s1[], s2[];
{
    int i;
    for(i=0;(s2[i] = s1[i]);i++);
    return s2;
}
void reverse(t)
char t[];
{
    int i = 0;
    int c;
    int j = strlen(t) - 1;
    
    for(i = 0; i < j; i++, j--) {
        c = t[i];
        t[i] = t[j];
        t[j] = c;
    }
}