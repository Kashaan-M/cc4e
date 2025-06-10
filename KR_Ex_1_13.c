#include <stdio.h>
/*
Ex 1.13: Write a program to convert its input to lower case, using a function lower(c) which returns c if c is not a letter, and the lower case value of c if it is a letter.

*/
int main() {
    int lower();
    int ch;

    while((ch=getchar()) != EOF) {
        putchar(lower(ch));
    }
}
int lower(a)
int a;
{ 
    int b = 0; 
    // if  a is between 'A' and 'Z' in ASCII then lowercase them and return lowercase character
    if(a >= 'A' && a <= 'Z') {
        b = a + 32;
        return b;
    }
    return a;
}