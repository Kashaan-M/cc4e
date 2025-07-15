#include<stdio.h>
#include<string.h>
#include "26_getch_ungetch.c"
#include "27_binary_search.c"

#define MAXWORD 20
#define LETTER 'a'
#define NKEYS (sizeof(keytab) / sizeof(struct key))
#define DIGIT '0'

char getword(w, lim) /* get next word from input */
char *w;
int lim;
{
    int c,t;
    char getch();
    void ungetch();
    
    if(type(c= *w++ = getch()) != LETTER) {
        *w = '\0';
        return(c);
    }
    while(--lim > 0) {
        t = type(c = *w++ = getch());
        if(t != LETTER && t != DIGIT) {
            ungetch(c);
            break;
        }
    }
    *(w-1) = '\0';
    return(LETTER);
}

type(c) /* return type of ASCII character */
int c;
{
    if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return(LETTER);
    else if (c >= '0' && c <= '9')
        return(DIGIT);
    else
        return(c);
}


int main() /* count C keywords */
 {    
    struct key keytab[] = {
        {"for", 0},
        {"while",0},
        {"int",0},
        {"char",0},
        {"long",0},
        {"float",0},
        {"double",0},
        {"void",0},
        {"break",0},
        {"case",0},
        {"switch",0},
        {"default",0},
        {"unsigned",0},
        {"continue",0},
        {"struct",0},
    };
    int n,t;
    char word[MAXWORD];
    int binary();

    while((t=getword(word, MAXWORD)) != EOF)
        if(t == LETTER)
            if((n=binary(word, keytab, NKEYS)) >= 0)
                keytab[n].keycount++;
    
    for(n=0; n < NKEYS; n++)
        if(keytab[n].keycount > 0)
            printf("here %d,%s\n",keytab[n].keycount, keytab[n].keyword);
}