#include<stdio.h>
int main(argc, argv) /* a version of 'echo' command in linux shell */
int argc;  /* argc gives the number of command line arguments the program was invoked with */
char *argv[]; /* pointer to an array of character strings that contain the arguments, one per string */
{
    int i;
    for(i =1;  i < argc; i++) {
        printf("%s%c", argv[i],(i < argc - 1) ? ' ' : '\n');
    }
}