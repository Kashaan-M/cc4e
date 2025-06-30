#include <stdio.h>

int main() {
    int x= 3;
    int *px; /* px is a pointer */
    int y;
    px = &x; /* we pass address of x variable to pointer px. The unary '&' operator gives the address of a variable or an array. */
    printf("current value of x is %d\n", *px);
    y = *px; /* The unary '*' operator treats its operand as the address of the ultimate target,and accesses the address to fetch the content  */
    y = y - 2;
    printf("value of x has changed now from 3 to  3-2 which is 1\n %d\n",y);
}