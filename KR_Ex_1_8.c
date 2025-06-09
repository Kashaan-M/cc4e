/*
Write a program to replace each tab by the three-character sequence >, backspace, -, which prints as >, and each backspace by the similar sequence <. This makes tabs and backspaces visible.
*/
#include <stdio.h>
int main() {
    int ch;

    while((ch=getchar()) != EOF) {
        if(ch == '\t') {
        printf("%c \b %c",'>','-');
        }
        else if (ch == '\b') {
            ch = '<';
            putchar(ch);
        }
        else {
            putchar(ch);
        }
    }
}