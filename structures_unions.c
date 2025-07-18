#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    union demo {
        int ia;
        float fa;
        char a[4];
    };
    union demo u;
    u.ia = 65;
    printf("%08x, %f, %s\n",u.ia, u.fa,u.a);
    strcpy(u.a,"ABC");
    printf("%08x, %f, %s\n",u.ia, u.fa,u.a);
    u.fa = 1.0/3.0;
    printf("%08x, %f, %s\n",u.ia, u.fa,u.a);
}