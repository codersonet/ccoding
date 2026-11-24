/* Q8: structure 'time' with hour, minute, second */
#include <stdio.h>

/* ---------- (i) three ways of declaring a variable ---------- */

/* (a) variable declared as part of the template */
struct time_a {
    int hour, minute, second;
} time_one;

/* (b) template and variable declared separately */
struct time_b {
    int hour, minute, second;
};
struct time_b time_two;

/* (c) using typedef */
typedef struct {
    int hour, minute, second;
} tmt;
tmt time_three;

/* for the remaining parts only the typedef version is used */
typedef tmt Time;

/* (iii) function to input time */
Time input_time() {
    Time t;
    printf("Enter hour minute second: ");
    scanf("%d %d %d", &t.hour, &t.minute, &t.second);
    return t;
}

/* (iii) function to display time */
void display_time(Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}

/* (iv) adds 'seconds' to the time and returns new time.
   Same carry rule as the question (60 sec -> 1 min, 60 min -> 1 hr,
   24 hr -> 0), done with / and % so big increments also work. */
Time update(Time t, int seconds) {
    long total = t.hour * 3600L + t.minute * 60L + t.second + seconds;
    total = total % (24 * 3600L);       /* hour 24 becomes 0 */
    t.hour = total / 3600;
    t.minute = (total % 3600) / 60;
    t.second = total % 60;
    return t;
}

int main() {
    Time t;
    int inc;

    /* (ii) assign values to members and display in different formats */
    time_one.hour = 16;  time_one.minute = 40;  time_one.second = 51;
    time_two.hour = 16;  time_two.minute = 40;  time_two.second = 51;
    time_three.hour = 16; time_three.minute = 40; time_three.second = 51;

    printf("time_one   : %d:%d:%d\n", time_one.hour, time_one.minute, time_one.second);
    printf("time_two   : %d/%d/%d\n", time_two.hour, time_two.minute, time_two.second);
    printf("time_three : %d.%d.%d\n", time_three.hour, time_three.minute, time_three.second);

    /* (iii) and (iv) */
    t = input_time();
    printf("Time entered: ");
    display_time(t);

    printf("Seconds to add: ");
    scanf("%d", &inc);
    t = update(t, inc);
    printf("Updated time: ");
    display_time(t);
    return 0;
}
