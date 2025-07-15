#include<stdio.h>
#include<string.h>

int main() {
char name[10] = {'a','b','c','d','e','f','g','h','i','j','k'};
int i;

printf("strlen(name)%ld sizeof(name)%ld",strlen(name),sizeof(name));
for(i=0; i < 2000; i++)
    printf("%d",name[i]);

}