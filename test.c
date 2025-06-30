#include <stdio.h>

int main() {
int a[10] = {'a','b','c','d','e','f','g','h','i','j'};

int *px;
/* alternate
 int *px = a; */
px = a;
/* alternate
px = &a[0];
*/
char x;
x = *px;

printf("a[0] = %c\na[1] = %c\na[2] = %c\na[3] = %c\n",*px,*(px+1),*(px+2),*(px+3));
}