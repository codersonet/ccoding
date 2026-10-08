#include <stdio.h>      //Include the standard input/output library for printf and scanf.

/* Start of the main function, where the program execution begins. */
int main() {
    /* Declare variables: n stores the user input, i is used in the loop, flag tracks prime-check status, and first, second, next store Fibonacci sequence values*/
    int n, i, flag = 0, first = 0, second = 1, next = 0;

    printf("Enter a positive integer: ");       //Prompt the user to enter a positive integer.

    scanf("%d", &n);      //Read the integer entered by the user and store it in n.

    /* If n is 2 or greater, check whether it is a prime number. */
    if (n >= 2) {
        /* Loop from 2 to the square root of n to test possible divisors. */
        for (i = 2; i * i <= n; i++) {
            /* If n is divisible by i, it is not prime. */
            if (n % i == 0) {
                /* Set flag to 1 to indicate a divisor was found. */
                flag = 1;
                // Stop the loop because the number is confirmed not to be prime.
                break;
            }
        }

        // If no divisor was found, print that the number is prime. 
        if (flag == 0)
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n);
    } 
    else {
        printf("%d is not a prime number.\n", n);       // Numbers less than 2 are not prime.
    }

    /* Reset the flag variable for the Fibonacci check. */
    flag = 0;
        /* Generate Fibonacci numbers until the next number is greater than or equal to n. */
    while (next < n) {
        /* Compute the next Fibonacci number as the sum of the previous two values. */
        next = first + second;
        /* Move the first value forward to the second value. */
        first = second;
        /* Move the second value forward to the newly computed next value. */
        second = next;
    }

    /* If the generated Fibonacci value matches n, then n is a Fibonacci number. */
    if (next == n)
        printf("%d is a Fibonacci number.\n", n);
    else
        printf("%d is not a Fibonacci number.\n", n);

    return 0;           //Return 0 to indicate the program ended successfully.
}
