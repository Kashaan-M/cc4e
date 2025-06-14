/*
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;

Write a loop equivalent to the for loop above without using &&.

Check KR_Ex_1_15.c for the complete program to get of this for loop.
*/
#include <stdio.h>
#define MAXLINE 1000

int main() {
    char s[MAXLINE];
    int c, i;
    int lim = MAXLINE;
    /*
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;
    */
    i = 0;
    while(i < lim - 1) {
        if((c=getchar()) != '\n' && c  != EOF) {
            s[i] = c;
        }
        ++i;
    }
}