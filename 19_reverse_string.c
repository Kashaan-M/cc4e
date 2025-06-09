#include <stdio.h>

int main() {
    void reversecopy();
    char a[60] = "hello I am your friend";
    char b[60];
    int i;
    int j;

    j=0;
    i=21;
    reversecopy(a,i,b);
    printf("b = %s \n a = %s \n",b,a);
}
void reversecopy(c,i,d) 
char c[], d[];
int i;
{
    int j = 0;

    while((d[j] = c[i]) !='\0') {
        /* printf("c[i]%c i %d d[j]%c j %d\n", c[i],i,d[j],j); */
        i--;
        j++;
    }

}