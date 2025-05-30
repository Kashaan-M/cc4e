#include <stdio.h>

int main() { // count digits , white space characters, others
int c , i, nwhite, nother;
int ndigit[10]; // Array with declaration mentioning constant 10 number of elements of int type at compile time.

nwhite = nother = 0;
for(i = 0; i < 10; ++i) {
    ndigit[i] = 0;
}
while((c = getchar()) != EOF) {
    if(c >= '0' && c <= '9') {
        ++ndigit[c - '0'];
    }
    else if(c == ' ' || c == '\n' || c=='\t') {
        ++nwhite;
    }
    else {
        ++nother;
    }
}
printf("digits = ");

for(i=0; i < 10; ++i) {
    printf("%d %d\n", i, ndigit[i]);
}
printf("\nWhite space = %d, other = %d\n", nwhite, nother);
}