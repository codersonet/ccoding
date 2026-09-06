/* Write a program to print the following numbers using different format specifiers: 
(i) int, (ii) short int, (iii) long int, (iv) float, (v) double, (vi) unsigned.
Your result/output must clearly state the result type, or it should be user-friendly.
Also Write Comments. */

#include <stdio.h>
#include <math.h>
int main(){
    int n = 10; // Declare an integer variable and initialize it.
    short int i = 11; // Declare a short integer variable and initialize it.
    long int t = 2026; // Declare a long integer varibale an initialize it.
    float s = 97.56; // Declare a float variable and initialize it.
    double k = 99.9984; // Declare a double variable and initialize it.
    unsigned int m = 11215; // Declare an unsigned integer variable and initialize it.

    printf("The value of int is: %d\n", n); // Print the value of integer variable.
    printf("The value of short int is: %hd\n", i); // Print the value of short integer variable.
    printf("The value of long int is: %ld\n", t); // Print the value of long integer variable.
    printf("The value of float is: %.2f\n", s); // Print the value of float variable with 2 decimal places.
    printf("The value of doiuble is: %.4lf\n", k); // Print the value of double variable with 4 decimal places.
    printf("The value of unsigned int is: %u\n", m); // Print the value of unsigned integer variable.
}