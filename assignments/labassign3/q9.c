/* Write programs in C for the following (with accuracy of 0.0001):
   (a) e = 1 + 1/1! + 1/2! + 1/3! + ...
   (b) sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
   (c) sum = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
*/

#include <stdio.h>
#include <math.h>
#define EPS 0.0001

double factorial(int n) {
    double result = 1.0;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/*
   Euler's number e = 1 + 1/1! + 1/2! + 1/3! + ...
   Logic:
   - Start with term = 1.0, which is 1/1!
   - Add term to sum
   - Divide term by the next integer to get the next factorial term
   - Stop when the next term becomes very small
*/
double eulerNumber(void) {
    double sum = 0.0;      // final sum of series
    double term;
    int n = 0;

    do {
        term = 1.0 / factorial(n);
        if (fabs(term) < EPS) {
            break;
        }
        sum += term;       // add current term to total
        n++;
    } while (1);
    return sum;
}

/*
   sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
   Logic:
   - First term is x
   - Every next term is obtained by multiplying the previous term by (-x^2)
   - Then divide by the next odd and even numbers
*/
double sinSeries(double x) {
    double sum = 0.0;      // final sum of sine series
    double term;
    int power = 1;         // current odd power (1, 3, 5, 7, ...)

    do {
        term = pow(x, power) / factorial(power);
        if (fabs(term) < EPS) {
            break;
        }
        if (((power - 1) / 2) % 2 != 0) {
            term = -term;
        }
        sum += term;       // add current term
        power += 2;        // go to next odd power
    } while (1);
    return sum;
}

/*
   Sum = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
   Logic:
   - term starts from 1.0, which is 1/1^1
   - next term is 1/2^2, then 1/3^3, then 1/4^4, ...
   - each new term uses the next value of n
*/
double reciprocalPowerSeries(void) {
    double sum = 0.0;      // final sum
    double term = 1.0;     // current term: 1/1^1, 1/2^2, 1/3^3, ...
    int n = 1;

    while (fabs(term) >= EPS) {
        sum += term;       // add current term
        n++;               // move to next n
        term = 1.0 / pow((double)n, (double)n);
    }
    return sum;
}

int main(void) {
    int choice;
    double x, result;

    printf("Choose one of the following series:\n");
    printf("1. Euler's number e\n");
    printf("2. sin(x)\n");
    printf("3. 1 + (1/2)^2 + (1/3)^3 + ...\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = eulerNumber();
        printf("e = %.6f\n", result);
    } 
    else if (choice == 2) {
        printf("Enter value of x in radians: ");
        scanf("%lf", &x);
        result = sinSeries(x);
        printf("sin(%.3f) = %.6f\n", x, result);
    } 
    else if (choice == 3) {
        result = reciprocalPowerSeries();
        printf("Sum = %.6f\n", result);
    } 
    else if (choice == 4) {
        printf("Program ended.\n");
    } 
    else {
        printf("Invalid choice!\n");
        return 1;
    }
    return 0;
}