/* A ’C’ Program contains the following statements:
#include<stdio.h>
int i, j, k;
Take the values of variables interactively and print output for each of the following
groups of variables or expressions in user friendly way. Assume all variables represent
decimal integers.
(a) i, j and k with a minimum field width of three characters per quantity.
(b) (i+j), (i-k) with a minimum field width of five characters per quantity.
(c) Sqrt(i+j), abs(i-k) with a minimum field width of nine characters for the first
quantity and seven characters for the second quantity.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    printf("Enter values for i, j, k: ");
    scanf("%d %d %d", &i, &j, &k);

    // i, j and k with a minimum field width of three characters per quantity.
    printf("(a) i = %3d, j = %3d, k = %3d\n", i, j, k);

    // (i+j), (i-k) with a minimum field width of five characters per quantity.
    printf("(b) i+j = %5d, i-k = %5d\n", i + j, i - k);

    /*Sqrt(i+j), abs(i-k) with a minimum field width of nine characters for the first
    quantity and seven characters for the second quantity. */
    printf("(c) sqrt(i+j) = %9.2f, abs(i-k) = %7d\n", sqrt(i + j), abs(i - k));

    return 0;
}