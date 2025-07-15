#include <stdio.h>
#define NAMSIZE 30
#define ADRSIZE 100

static struct date {
    int day;
    int month;
    int year;
    int yearday;
    char mon_name[4];
};

static struct person {
    char name[NAMSIZE];
    char address[ADRSIZE];
    long zipcode;
    long ss_number;
    struct date birthdate;
    struct date hiredate;
};

int main(argc,argv)
int argc;
char *argv[];
{
   
    struct date a = { 28,06,2025,195,"Sat"};
    printf("%d-%d-%d,  %d / 365, %s\n\n", a.day, a.month, a.year, a.yearday, a.mon_name);
  
    struct person kashaan = { 
        "Kashaan Mahmood",
        "House # 1653, Street # 29, I-14/4, Islamabad, Pakistan.",
        46000,
        3740557822479,
        { 9,6,1994,160,"Fri" },
        { 30,30,3000,150,"Fri" },
         };

    printf("****Person***\nName: %s\nAddress: %s\nZipcode: %ld\nSS_number: %ld\n",kashaan.name,kashaan.address,kashaan.zipcode,kashaan.ss_number);
    printf("Birthday: %d-%d-%d, %d/365, %s\n",kashaan.birthdate.day, kashaan.birthdate.month, kashaan.birthdate.year, kashaan.birthdate.yearday, kashaan.birthdate.mon_name);
    printf("Hire Date: %d-%d-%d, %d/365, %s\n\n",kashaan.hiredate.day, kashaan.hiredate.month, kashaan.hiredate.year, kashaan.hiredate.yearday, kashaan.hiredate.mon_name);

    struct person mahmood = kashaan; // copying struct person kashaan to struct person mahmood for testing copying of structures as a unit
    struct person *kashp = &mahmood;
    void greet();
    /* structures cannot be passed to a function as argument or returned 
    from a function however pointers to a structure can be passed and returned*/
    greet(kashp);   
}
void greet(p)
struct person *p;
{
    printf("hello %s\n", p->birthdate);
}