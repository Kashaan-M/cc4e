#include <stdio.h>
int main() {
    char line[1000];
    printf("Enter line\n");
    // it is safer to use fgets() in place of scanf()
  	fgets(line, 1000, stdin);
    /* fgets says: put 1000 characters while looking after new line character(\n) and read from stdin i.e. standard input */
  	printf("Line: %s\n",line);
}