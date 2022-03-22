
#include <stdio.h>


typedef struct {
    int year;
    int month;
    int day;
} Date;

void print_date(Date d) {
    printf("My birthday is: %04d-%02d-%02d\n", d.year, d.month, d.day);
}

int main() {
    Date d = { .year = 1997, .month = 06, .day = 16 };
    print_date(d);
    return 0;
}