#include <stdio.h>

int main(argc,argv)
int argc;
char *argv[];
{
    struct date {
        int day;
        int month;
        int year;
        int yearday;
        char mon_name[4];
    };
    struct date a = { 28,06,2025,195,"Sat"};
    printf("%d-%d-%d,  %d / 365, %s\n", a.day, a.month, a.year, a.yearday, a.mon_name);
}