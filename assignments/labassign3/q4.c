/*
Write a program to read a floating-point number (decimal number) and display the
following:
(i) (ii) (iii) (iv) (v) Right most digit of the integer part of the number.
The integer part of given number.
Smallest integer not less than the number.
Largest integer not greater than the number.
Find the sum of all the digits in the real number given as input.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double num;          // input number
    double absNum;       // absolute value of the input number
    int intPart;         // integer part of the number (truncated toward zero)
    double ceilVal;      // smallest integer >= number
    double floorVal;     // largest integer <= number
    long long whole;     // integer portion without decimal point
    long long fraction;  // decimal portion scaled to 6 digits
    int digitSum = 0;    // sum of all digits in the number
    long long temp;      // temporary variable used while calculating digit sum

    printf("Enter a floating-point number: ");          // Asking floating-point number to user
    scanf("%lf", &num);

    absNum = (num < 0) ? -num : num;        // Store absolute value to handle negative input safely

    intPart = (int)num;      // Find integer part of the number
    printf("(i) Rightmost digit of the integer part: %d\n", abs(intPart % 10));

    printf("(ii) Integer part of the number: %d\n", intPart);           // Print the integer part itself

    // Use ceil() to get the smallest integer not less than the number
    ceilVal = ceil(num);
    printf("(iii) Smallest integer not less than the number: %.0f\n", ceilVal);

    //Use floor() to get the largest integer not greater than the number
    floorVal = floor(num);
    printf("(iv) Largest integer not greater than the number: %.0f\n", floorVal);

    // Extract digits from the real number
    whole = (long long)absNum;      // Integer part digits

    fraction = (long long)llround((absNum - whole) * 1000000.0);        // Fractional part digits: multiply by 1000000 to keep 6 decimal places

    temp = whole;       // Add digits of the integer part
    while (temp > 0)
    {
        digitSum += temp % 10;
        temp /= 10;
    }

    temp = fraction;        // 7.4) Add digits of the fractional part
    while (temp > 0)
    {
        digitSum += temp % 10;
        temp /= 10;
    }

    printf("(v) Sum of all digits in the real number: %d\n", digitSum);     // Step 8: Print the sum of all digits in the real number

    return 0;
}

