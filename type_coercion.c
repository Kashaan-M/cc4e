#include<stdio.h>
#include<math.h> // for pow()
#include<stdlib.h> // for strtol()



/*
The C stdlib library strtol() function is used to convert a string to a long 
integer number according to the given base. which must be lies between 2 and 32 inclusive, or be the special value 0.

Following is the C library syntax of the strtol() function −

long int strtol(const char *str, char **endptr, int base)

This function accepts following parameters −

    str − It is a string to be converted into a long integer value.

    endptr − It is a pointer to a charter pointer and used to store the pointer to the first character after the numeric value.

    base − It represents the base of the number system(e.g., 10 for decimal and 16 for hexadecimal).

Return Value
This function returns the converted long integer value. If the input string is not a valid, it returns 0.

The example below convert a decimal number string to a long decimal integer, using the strtol() function.
Open Compiler

#include <stdio.h>
#include <stdlib.h>

int main() {
   const char *str = "12205";
   char *endptr;
   long int num;

   // Convert the string to a long integer
   num = strtol(str, &endptr, 10);
   
   //display the long integer number    
   printf("The number is: %ld\n", num);    
   return 0;
}

Output

Following is the output −

The number is: 12205

*/

int main()
{
    char a_arr[10];
    long int a;
    char b_arr[10];
    long int b;
    char *end;

    printf("Enter base\n");
    fgets(a_arr,sizeof(a_arr),stdin);
    a = strtol(a_arr,&end,10);

    printf("\nEnter exponent\n");
    fgets(b_arr,sizeof(b_arr),stdin);
    b = strtol(b_arr,&end,10);

    printf("%f\n", pow(a,b));
}
