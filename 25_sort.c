#include<stdio.h>
#include<string.h>
#include "18_get_line.c"
#include "21_alloc_free.c"
#define LINES 100 /* max lines to be sorted */

#define MAXLEN 1000
int readlines(lineptr, maxlines) /* read input lines */
char *lineptr[]; /* for sorting */
int maxlines;
{
    extern int get_line();
    int len, nlines;
    char *p, line[MAXLEN];
    extern void *alloc();

    nlines = 0;
    while((len = get_line(line,MAXLEN)) > 0) {
        if(nlines >= maxlines)
            return(-1);
        else if ((p=alloc(len)) == NULL)
            return(-1);
        else {
            line[len-1] = '\0'; /* zap newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return(nlines);
}

void sort(v, n) /* sort strings v[0] v[n-1] */
char *v[];  /* into increasing order*/
int n;
{
    int gap, i, j;
    char *temp;
    printf("\ninside sort,n=%d,n/2=%d\n",n,n/2);
    for(gap=n/2; gap > 0; gap /= 2) {
        printf("n=%d, gap=%d\n",n,gap);
        for(i = gap; i < n; i++) {
            printf("i=%d\n",i);
            for(j = i - gap; j >= 0; j -= gap) {
                printf("j=%d\n",j);
                if (strcmp(v[j], v[j+gap]) <= 0) {
                    printf("if True\n");
                    break;
                }
                temp = v[j];    /* these three lines of code swap positions of */  
                v[j] = v[j+gap]; /* the earlier shorter line with the later longer line in v[j] array */
                v[j+gap] = temp;
                printf("v[j]=%s, v[j+gap]=%s\n",v[j],v[j+gap]);
            }
        }
    }
    printf("the loops didn't run\n");
}

void writelines(lineptr, nlines) /* write output lines */
char *lineptr[];
int nlines;
{
    int i;
    for(i=0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* Main */

int main() /* sort input lines */
{
char *lineptr[LINES]; /* pointers to text lines */
int nlines; /* number of input lines read */

if((nlines = readlines(lineptr, LINES)) >= 0) {
    sort(lineptr, nlines);
    printf("\n\nsort finish\n\n");
    writelines(lineptr, nlines);
}
else 
    printf("input too big to sort\n");
}