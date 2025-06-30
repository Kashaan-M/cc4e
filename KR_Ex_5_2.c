/*
Write the pointer version of strcat()

strcat(s, t) // concatenate t to end of s 
char s[], t[]; // s must be big enough
{
int i, j;
i = j = 0;
while (s[i] != '\0') // find end of s 
i++;
while ((s[i++] = t[j++]) != '\0') // copy t 
;
}
*/
#include<stdio.h>
#include<string.h>
#define MAXLEN 100
int main()
{
    void strcat2();
    char s[MAXLEN];
    char t[MAXLEN];
    printf("---Concatenate two strings----\n");
    printf("Enter first string\n");
    fgets(s,MAXLEN,stdin);
    printf("\nEnter Second String\n");
    fgets(t,MAXLEN,stdin);
    strcat2(&s, &t);
    printf("%s %ld", s, strlen(s));
}
void strcat2(s1,s2)
char *s1, *s2; // pointers to character arrays
{
    int i , j;
    i =0; j = 0;

    while(s1[i] != '\0')
        i++;

    while((s1[i] = s2[j]) != '\0') {
        i++;
        j++;
    }
}