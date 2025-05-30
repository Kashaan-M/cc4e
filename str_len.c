#include <stdio.h>
#include <string.h>

int main() {
    char c[1000];
    printf("Enter Character: ");
    scanf("%s", c);
    printf("Char length: %ld\n", strlen(c));
}