/*
Write an alternate version of squeeze(s1, s2) which deletes each character in s1 which matches any character in the string s2.

queeze(s, c) / delete all c from s /
char s[];
int c;
{
  int i,  j;

  for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
  s[j] = '\0';
}
*/
#include <stdio.h>
#define MAXSIZE 100

int main() {
    void squeeze();
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    
    printf("\n*** Remove each character in the first string from the second string ***\n\n");
    printf("Enter first string:\n");
    fgets(s1,MAXSIZE,stdin);
    printf("\n\nEnter second string:\n");
    fgets(s2,MAXSIZE,stdin);
    squeeze(s1,s2);
    printf("\n\nResult:\n%s\n", s2);
}
void squeeze(s1,s2) /* Delete each character in s1 from s2 */ // eg s1=balso,s2=because he lives there, result=ecue he ive there
char s1[];
char s2[];
{
    int i, j, k;
    for(i=0; s1[i] != '\0'; i++) {
        for(j=k=0; s2[j] != '\0'; j++) {
            if(s2[j] != s1[i])
                s2[k++] = s2[j];
        }
        s2[k] = '\0';
    }
    s1[i] = '\0';
}