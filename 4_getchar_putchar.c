#include <stdio.h>

int main() {
    int c=48;

    printf("%c", c);

    c = getchar();
    while(c != EOF) {
        putchar(c);
        printf("%d\n",c+2);
        c = getchar();
    }
}