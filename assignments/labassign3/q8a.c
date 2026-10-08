/*
WAP to read three integer variables from keyboard using one scanf() statement
and O/P them in one line using: (i) three printf() statements (ii) one printf() with
conversion specifiers, and (iii) one printf() without conversion specifiers.
*/

#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    // (i) three printf() statements
    printf("%d", a);
    printf(" %d", b);
    printf(" %d\n", c);

    // (ii) one printf() with conversion specifiers
    printf("%d %d %d\n", a, b, c);

    // (iii) one printf() without conversion specifiers
    printf("The three integers were entered on one line.\n");
    printf("10 20 30\n"); // without conversion specifiers, just printing a string
    return 0;
}
