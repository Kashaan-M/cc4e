#include <stdio.h>
/*
Read set of lines and print the longest line.

The basic outline of this program
while(there is another line)
    if(it is longer than the previous longest)
    save it and its length
print longest line
*/
#define MAXLINE 1000 /* maximum input line size */
int main() { /* find longest line*/

    int get_line();
    void copy();

    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line saved */

    max = 0;
    while((len=get_line(line, MAXLINE)) > 0) {
        if(len > max) {
            max = len;
            copy(line, save);
        }
    }
    if(max > 0) /* there was a line */
        printf("%s %d\n",save,max);
}
int get_line(s, lim) /* get line into s, return length */
char s[];
int lim;
{
    int c,i;
    for(i=0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) 
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}
void copy(s1, s2) /* copy s1 to s2, assume s2 big enough */
char s1[], s2[];
{
    int i;
    i = 0;
    while((s2[i] = s1[i]) != '\0')
        ++i;
}
/*
void reversecopy(s1,i,s2) */ /* reverse copy s1 to s2, assume s2 is big enough */

/*
char s1[], s2[];
int i;
{
    int j = 0;
    
    while((s2[j] = s1[i]) != '\0') {
        i--;
        j++;
    }
}
*/