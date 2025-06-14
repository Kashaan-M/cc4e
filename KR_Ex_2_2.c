/*
Write the function htoi(s), which converts a string of hexadecimal digits into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F.
*/
#include <stdio.h>
#include <string.h>
#define MAXSIZE 10  /* Maximum characters*/
#define YES 1
#define NO 0
int dec;  /* External variable. The decimal result of the hexadecimal number*/

int main() {
    int power();
    int htoi();
    char hex[MAXSIZE];
    extern int dec;

    printf("\n*** Hexadecimal to Decimal Converter ***\n\nEnter Hexadecimal number\n");
    fgets(hex,MAXSIZE,stdin);
    if(htoi(hex)) {
        printf("\ninput is hexadecimal\n\n");
        printf("Hexadecimal: %s\nDecimal: %d\n",hex,dec);
    }
    else
        printf("\ninput is not hexadecimal. Try again.\n");
}

int power(x, n) /* raise x to n-th power; n > 0 */
int x, n;
{
    int i,p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * x;
    return (p);
}
int htoi(h)
char h[];
{
    extern int dec;
    dec = 0;
    int i;
    int is_hex = NO; /* result accumulator */
    int hex = 0; /* variable to store temporary hexadecimal value of a character*/
    int exp;

    for(i=0; h[i] && h[i] != '\n'; i++) {
        switch(h[i]) {
            case '0': 
                is_hex = YES;
                hex = 0;
                break;
            case '1':
                is_hex = YES;
                hex = 1;
                break;
            case '2':
                is_hex = YES;
                hex = 2;
                break;
            case '3':
                is_hex = YES;
                hex = 3;
                break;
            case '4':
                is_hex = YES;
                hex = 4;
                break;
            case '5':
                is_hex = YES;
                hex = 5;
                break;
            case '6':
                is_hex = YES;
                hex = 6;
                break;
            case '7':
                is_hex = YES;
                hex = 7;
                break;
            case '8':
                is_hex = YES;
                hex = 8;
                break;
            case '9':
                is_hex = YES;
                hex = 9;
                break;
            case 'A':
                is_hex = YES;
                hex = 10;
                break;
            case 'B':
                is_hex = YES;
                hex = 11;
                break;
            case 'C':
                is_hex = YES;
                hex = 12;
                break;
            case 'D':
                is_hex = YES;
                hex = 13;
                break;
            case 'E':
                is_hex = YES;
                hex = 14;
                break;
            case 'F':
                is_hex = YES;
                hex = 15;
                break;
            case 'a':
                is_hex = YES;
                hex = 10;
                break;
            case 'b':
                is_hex = YES;
                hex = 11;
                break;
            case 'c':
                is_hex = YES;
                hex = 12;
                break;
            case 'd':
                is_hex = YES;
                hex = 13;
                break;
            case 'e':
                is_hex = YES;
                hex = 14;
                break;
            case 'f':
                is_hex = YES;
                hex = 15;
                break;
            default:
                is_hex = NO;
                break;
        }
        
        if(!is_hex) {
            break;
        }

        exp = ((strlen(h)-2)-i);
        dec  +=  hex * power(16, exp);
       /*
        printf("exp hex %d %d\n", exp,hex);
        printf("d %d\n", d);
       */
    }
    /* printf("is_hex %d\n",is_hex); */
    return(is_hex);
}