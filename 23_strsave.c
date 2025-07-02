#include<stdio.h>
#include<string.h>
#include "21_alloc_free.c"

int main() {
    char *txt = "Hello world";
    char *strsave();
    char *ret;
    ret = strsave(&txt);
    printf("%s", ret);
}
char *strsave(s) /* save string s somewhere */
char *s;
{
    char *p, char *alloc();
    if((p = alloc(strlen(s)+1)) != NULL)
        strcpy(p,s);
    return(p);
}