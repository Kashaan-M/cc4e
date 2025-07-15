#include<stdio.h>
#include<string.h>

extern struct key {
        char *keyword;
        int keycount;
};

int binary(word, tab,n) /* find word in tab[0]...tab[n-1] */
char *word;
struct key tab[];
int n;
{
    int low, high,mid,cond;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low+high) / 2;
        if((cond = strcmp(word, tab[mid].keyword)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else /* match found i.e. strcmp() returned 0 */
            return(mid);
    }
    return(-1);
}

