#include <stdio.h>
/* Print Fahrenheit Celsius table
*/

int main() {
    int lower, upper , step;
    float fahr, cels;
    int ans;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

        printf("Fahr\t\tCels\t\t\n");
    while(fahr <= upper) {
        cels = (fahr - 32.0) * (5.0/9.0);
        printf("%4.2f %6.2f\n", fahr, cels);
        fahr = fahr + step;
    }
}