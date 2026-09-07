/* Can we use the floating-point variable/constant for counting? WAP to print number
1 (one) using %d and %f and write a comment on your result. */

#include <stdio.h>
int main() {
    float a = 1.0; // Declare a floating-point variable and initialize it to 1.0.
    printf("The value of a using %%d is: %d\n", (int)a); // Print the value of a using %d format specifier by typecasting it to int.
    printf("The value of a using %%f is: %f\n", a); // Print the value of a using %f format specifier.
    return 0;
}