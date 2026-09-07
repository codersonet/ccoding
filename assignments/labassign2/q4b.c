/* A ‘C’ programming contains the following statement:
#include <stdio.h>
float x, y, z;
Take the values of variables interactively and print output for each of the following
groups of variables or expressions for each floating-point quantity in user friendly way.
(a) x, y, and z, with a minimum field width of eight characters per quantity and no more
than four decimal places.
(b) (x+y), (x-z) with a minimum field width of nine characters per quantity, with no
more than three decimal places.
(c) Sqrt (x+y), abs(x-z) with a minimum field width of 12 characters for the first
quantity and 10 characters for the second. Display a maximum of four decimal
places for each quantity.*/

#include <stdio.h>
#include <math.h>
int main() {
    float x, y, z;
    printf("Enter values for x, y, z: ");
    scanf("%f %f %f", &x, &y, &z);
    // (a) x, y, and z, with a minimum field width of eight characters per quantity 
    // and no more than four decimal places.
    printf("(a) x = %8.4f, y = %8.4f, z = %8.4f\n", x, y, z);
    // (b) (x+y), (x-z) with a minimum field width of nine characters per quantity
    // with no more than three decimal places.
    printf("(b) x+y = %9.3f, x-z = %9.3f\n", x + y, x - z);
    // (c) Sqrt (x+y), abs(x-z) with a minimum field width of 12 characters for the first
    // quantity and 10 characters for the second. Display a maximum of four decimal
    // places for each quantity.
    printf("(c) sqrt(x+y) = %12.4f, abs(x-z) = %10.4f\n", sqrt(x + y), fabs(x - z));
    return 0;
}