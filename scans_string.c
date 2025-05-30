#include <stdio.h>

int main() {
    int i;
    char name[20];
    for(i=0; i<=5;++i) {
    printf("Enter Name:\n");
    scanf("%20s", name);
    printf("Hello %s\n", name);
    }
}