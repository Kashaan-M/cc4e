#include <stdio.h>

int main() {
    char line[1000];
    FILE *hand;
    /* FILE is a type defined in <stdio.h>. *hand is pointer to a file.*/
    hand = fopen("romeo.txt","r"); // fopen() in C is a lot like open() in python
    while(fgets(line,1000,hand) != NULL) { 
        /* fgets() returns NULL, which is a constant defined in stdio.h, when it reaches the end of file*/
        printf("%s",line);
    }
    printf("\n");
}