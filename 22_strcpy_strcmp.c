#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[] = "Hello My name is Kashaan";
    char s2[] = "I am Ali";
    char s3[] = "Hello My name is Kashaan";
    char s4[] = "I am from ";
    char s5[] = "Pakistan";
    /* strcmp(s1,s2) compares two strings. if s2 == s1 it returns 0, if s2 > s1 it returns 1. if s2 < s1 it returns -1 */
    printf("%d\n", strcmp(s2,s3));
    /* strcpy(s1,s2) copies the string s2 to the string s1. It overwrites s1. */
    strcpy(s4,s5);
    printf("%s\n", s4);
}