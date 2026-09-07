/* How and why are the comments (2 methods) written in ‘C’ HLL? Write a program for
4 basic operations of mathematics and comment properly using two different methods
used in ‘C’ HLL. */

#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // Addition
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    // Subtraction
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    // Multiplication
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    // Division
    if (b != 0) {
        printf("Division: %d / %d = %.2f\n", a, b, (float)a / b);
    } 
    else {
        printf("Division by zero is not allowed.\n");
    }
    return 0;
}