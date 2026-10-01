#include <stdio.h>
#include <stdbool.h>

int printPrimes() {		// defining a function to print prime numbers
    for (int num = 1; num <= 100; ++num) {
        if (num <= 1) 		// continue if the number is less than or equal to 1
		continue;
        bool isPrime = true;		// define bool isPrime()
        if (num == 2) {				// checking only even prime number = 2
            isPrime = true;
        } 
		else if (num % 2 == 0) {	// removing all even numbers other than 2
            isPrime = false;
        } 
		else {
            for (int i = 3; i * i <= num; i += 2) {			// checking odd numbers if they are prime or not
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            printf("%d ", num);				// printing prime numbers
        }
    }
    printf("\n");			// new line after printing all prime numbers between 1-100
}

int main() {			
    printPrimes();		// calling printPrimes() functions
    return 0;			// returning zero after successful execution
}
