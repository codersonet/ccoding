/* Q9: structure 'date' - read, validate, print, update, nextdate, compare */
#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

const char *month_name[] = {"", "January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap(year))
        return 29;
    return days[month];
}

/* (i) read day, month, year */
Date read_date() {
    Date d;
    printf("Enter day month year: ");
    scanf("%d %d %d", &d.day, &d.month, &d.year);
    return d;
}

/* (ii) returns 1 if date is valid, 0 otherwise */
int is_valid(Date d) {
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1)
        return 0;
    return d.day <= days_in_month(d.month, d.year);
}

/* (iii) print like: April 29, 2002 */
void print_date(Date d) {
    printf("%s %d, %d\n", month_name[d.month], d.day, d.year);
}

/* (iv) increase date by one day */
Date update(Date d) {
    d.day++;
    if (d.day > days_in_month(d.month, d.year)) {   /* last day of month */
        d.day = 1;
        d.month++;
        if (d.month > 12) {                          /* last day of December */
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

/* (v) read date as long integer like 19450815 */
Date read_long_date() {
    Date d;
    long n;
    printf("Enter date as yyyymmdd: ");
    scanf("%ld", &n);
    d.year = n / 10000;
    d.month = (n / 100) % 100;
    d.day = n % 100;
    return d;
}

/* (vi) add 'n' days to a date. Jumps month by month instead of
   adding one day at a time, so it is quick even for large n */
Date nextdate(Date d, int n) {
    int left;
    while (n > 0) {
        left = days_in_month(d.month, d.year) - d.day;  /* days left in this month */
        if (n <= left) {
            d.day += n;
            n = 0;
        } else {
            n -= left + 1;       /* move to 1st of next month */
            d.day = 1;
            d.month++;
            if (d.month > 12) {
                d.month = 1;
                d.year++;
            }
        }
    }
    return d;
}

/* (vii) returns 1 if d1 is earlier than d2, 0 otherwise */
int compare_dates(Date d1, Date d2) {
    if (d1.year != d2.year)
        return d1.year < d2.year;
    if (d1.month != d2.month)
        return d1.month < d2.month;
    return d1.day < d2.day;
}

int main() {
    Date d1, d2, next;
    int n;

    /* (i)-(iii) read, validate and print */
    do {
        d1 = read_date();
        if (!is_valid(d1))
            printf("Invalid date, try again.\n");
    } while (!is_valid(d1));
    printf("Date: ");
    print_date(d1);

    /* (iv) next day */
    next = update(d1);
    printf("Next day: ");
    print_date(next);

    /* (v) long integer input */
    d2 = read_long_date();
    if (!is_valid(d2)) {
        printf("Invalid date from long integer.\n");
        return 0;
    }
    printf("Date from long integer: ");
    print_date(d2);

    /* (vi) add n days */
    printf("Days to add to first date: ");
    scanf("%d", &n);
    next = nextdate(d1, n);
    printf("After %d days: ", n);
    print_date(next);

    /* (vii) compare the two dates */
    printf("compare(date1, date2) = %d\n", compare_dates(d1, d2));
    return 0;
}
