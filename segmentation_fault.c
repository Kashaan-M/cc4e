#include <stdio.h>

int main() {
    /* This is an example of Buffer overrun errors. */
    char x[10];
    int i;
    for(i=0; i < 1000; i++) {
        x[i] = '*';
    }
        printf("%s\n",x);
}