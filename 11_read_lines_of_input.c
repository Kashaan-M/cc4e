#include <stdio.h>
int main() {
  	char line[100];
    printf("Enter line\n");
  	scanf("%100[^\n]s",line);
  	printf("Line: %s\n", line);
}