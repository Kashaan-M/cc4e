#include <stdio.h>
#define MAXLEN 10000
int main() {
    int i=0,j=0,k=0;
    int c;
    char strlist[MAXLEN], revlist[MAXLEN];

    for(i=0; (c=getchar()) != EOF; ++i) {
        strlist[i] = c;
    }
    strlist[i] = '\0';
    for(k=i; j <=i;k--) {
        /*printf("i %d j %d k %d", i,j,k);*/
        if(strlist[k] != '\0') {
            revlist[j] = strlist[k];
            j++;
            /*printf("this ran %c", strlist[12]);*/
        }
    }
    printf("%s\n",revlist);
}