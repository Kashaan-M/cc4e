#include <stdio.h>

int main() {
    int mymult();
    int retval;

    retval = mymult(5,3);
    printf("Answer : %d\n", retval);
}

int mymult(a,b) 
    int a,b;
    /* In C, we have to tell the function what type of arguments it is expecting. for e.g. a,b are type int. */
{
    int c = a * b;
    /* variable c of type int is only defined in the scope of mymult() function and not in main().*/
    return c;
}