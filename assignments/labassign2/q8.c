/* Write a program to print the following number in useful number system. 
(Schuam’s outlines/4ed/pg. 4.21)
S.no.     System       Format specifier      Type qualifier
1         Decimal            %d                 short (h)
2         Hexadecimal        %x or %X           long, signed (L or l)
3         Octadecimal        %0 or %O           Unsigned (u)
4         Exponential   %<w.d>e or %<w.d>E      Double (l)
(a) ‘A’ (b) 42AH (c) 0.3e-12 (d) 10.66E+8 (e) 0743 (octal) (f) 123,25 */

#include <stdio.h>
int main() {
    char a = 'A'; // Declare a character variable and initialize it.
    int b = 0x42A; // Declare an integer variable and initialize it with hexadecimal value.
    double c = 0.3e-12; // Declare a double variable and initialize it with exponential value.
    double d = 10.66E+8; // Declare a double variable and initialize it with exponential value.
    int e = 0743; // Declare an integer variable and initialize it with octal value.
    double f = 123.25; // Declare a double variable and initialize it with a decimal value.
    printf("Character: %c\n", a);
    printf("Hexadecimal: %x\n", b);
    printf("Exponential: %10.2e\n", c);
    printf("Exponential: %10.2e\n", d);
    printf("Octal: %o\n", e);
    printf("Float-point: %lf\n", f);
    return 0;
}