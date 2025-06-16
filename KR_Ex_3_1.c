/*
Write a function expand(s, t) which converts characters like newline and tab into visible escape
sequences like \n and \t as it copies the string s to t. Use a switch statement.
*/
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int main() {
    void expand();
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    printf("\nReplace newline and tabs with \\n and \\t");
    printf("\nEnter string:\n");
    expand(s1,s2);
    printf("\nResult:\n%s\n",s2);
    /* printf("s1 length: %ld, s2 length: %ld\n", strlen(s1)-1, strlen(s2)-1); */
}
void expand(s1,s2)
char s1[];
char s2[];
{
    int i = 0;
    int j = 0;
    int c;

    while((c=getchar()) != EOF) {
        switch (c) {
            case '\n':
                s1[i] = c;
                s2[j] = '\\';
                j++;
                s2[j] = 'n';
                break;
            case '\t':
                s1[i] = c;
                s2[j] = '\\';
                j++;
                s2[j] = 't';
                break;
            default:
                s1[i] = c;
                s2[j] = s1[i];
                break;
        }
        i++;
        j++;
    }
    s1[i] = '\0';
    s2[j] = '\0';
}