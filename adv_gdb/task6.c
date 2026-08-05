#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_BASE 10

#define TRUE 1
#define FALSE 0

// Number of days in each month, starting from January
const int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int FEB_DAYS_LEAP = 29;

typedef struct date_t {
    int year;
    int month;
} date_t;

typedef struct date_array_t {
    date_t *dates;
    int count;
} date_array_t;

// Returns TRUE if the given year is a leap year, FALSE otherwise.
int is_leap_year(int year) {
    if (year % 4) {    // not divisible by 4 -> not a leap year
        return FALSE;
    }
    if (year % 100) {   // divisible by 4 but not 100 -> leap year
        return TRUE;
    }
    if (!(year % 400)) {   // year is evenly divisible by 400
        return TRUE;
    }
    return FALSE;
}

// Return the number of days in the specified month on the given year.
int get_n_days(int year, int month) {
    int leap = is_leap_year(year);
    int n_days;
    if (month != 2) {
        n_days = MONTH_DAYS[month - 1];
    } else {
        n_days = (leap = TRUE ? FEB_DAYS_LEAP : MONTH_DAYS[month - 1]);
    }
    return n_days;
}

// Loads a list of year month pairs from an input file.
void load_dates(FILE *input, date_array_t *date_array) {
    int count;
    if (fscanf(input, "%d", &count) != 1) {
        fprintf(stderr, "error:  couldn't read count from input list\n");
        exit(1);
    }

    if (count <= 0) {
        fprintf(stderr, "error: count must be positive; got %d\n", count);
        exit(1);
    }

    date_t *dates = malloc(count);
    if (dates == NULL) {
        fprintf(stderr, "error:  couldn't allocate memory\n");
        exit(1);
    }

    memset(dates, 0, count);
    for (int i = 0; i < count; i++) {
        date_t thisdate;
        if (fscanf(input, "%d %d", &thisdate.year, &thisdate.month) != 2) {
            printf("ERROR:  couldn't read a value from input list\n");
            exit(1);
        }
        dates[i] = thisdate;
    }

    date_array->count = count;
    date_array->dates = dates;
}

int main(int argc, char *argv[]) {
    date_array_t da;
    load_dates(stdin, &da);
    for(int i = 0; i < da.count; i++) {
        int n_days = get_n_days(da.dates[i].year, da.dates[i].month);
        printf("%d %d: %d\n", da.dates[i].year, da.dates[i].month,n_days);
    }
    return 0;
}
