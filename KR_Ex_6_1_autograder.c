/*
Simple Structures

You will write two function dealing with a simple strcuture as shown below. The first function will dump the internal values of the simpledate structure. 
The second will compute the day of the year similar to the sample code in Chapter 6 of the K&R book. 

Expected output from your program:

Playing with structures
2023/02/11
Day of year 42
2023/09/15
Day of year 258
2024/09/15
Day of year 259
*/

#include <stdio.h>
#include <stdlib.h>

struct simpledate {
    int day;
    int month;
    int year;
};

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(pd) /* set day of year from month, day */
struct simpledate *pd;
{   // Pseudocode
    // 1 determine if the current year is leap year or not
    // 2 get index of current month in day_tab[2][13] in one of the [2] arrays
    // 3 sum the days of previous months and add the current days and return them

    // every fourth year is a leap year
    int is_leap_year = (pd->year % 4 == 0) ? 1 : 0;
    int total_days = 0;
    int i;

    for(i=0; i < pd->month; i++) {
        if(is_leap_year)
            total_days += day_tab[1][i];
        else
            total_days += day_tab[0][i];
    }
    // add days of current month to total_days
    total_days += pd->day;

    return total_days;
}

void dump_date(pd) /* print date from year, month, day */
struct simpledate *pd;
{
    /* The date should be in the following format - note that */
    /* The month and day are always two digits with leading zeros */
    printf("%d/%.2d/%.2d\n", pd->year, pd->month, pd->day);
}

int main() {
    void dump_date();
    printf("Playing with structures\n");
    struct simpledate sd;

    sd.year = 2023;
    sd.month = 2;
    sd.day = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2023;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2024;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
}