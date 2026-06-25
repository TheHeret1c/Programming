#include <stdio.h>

typedef struct {
    unsigned int day   : 5;
    unsigned int month : 4;
    unsigned int year_offset : 8;
} date;

int main(void) {
    date d;
    int tmp_day, tmp_month, full_year;

    printf("Enter day (1-31): ");
    scanf("%d", &tmp_day);
    d.day = tmp_day;

    printf("Enter month (1-12): ");
    scanf("%d", &tmp_month);
    d.month = tmp_month;

    printf("Enter year (e.g., 2024): ");
    scanf("%d", &full_year);
    d.year_offset = full_year - 1970;

    printf("\nDate: %02u.%02u.%04d\n", d.day, d.month, 1970 + d.year_offset);
    printf("Structure size: %zu bytes\n", sizeof(date));

    return 0;
}