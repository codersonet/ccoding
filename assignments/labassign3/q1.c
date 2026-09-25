#include <stdio.h>
int main() {
    // Variables to store the user's input and the counts
    int num;
    int pcount = 0;
    int ncount = 0;
    char choice = 'y'; 			// Initialize choice to 'y' to enter the loop
    // while loop continues as long as the user wishes
    while (choice == 'y' || choice == 'Y') {
        
        // Uses printf() and scanf() for input/output
        printf("Enter an integer: ");
        scanf("%d", &num);

        // if-else statement: check if the number is positive or negative
        if (num > 0) {
            pcount++; 		// Increment positive count
        } else if (num < 0) {
            ncount++; 		// Increment negative count
        } else {
            printf("Zero is neither positive nor negative.\n");
        }
        // Ask the user if they want to continue
        printf("Do you want to enter another number? (y/n): ");
        // The space before %c helps to skip any leftover newline characters in the input buffer
        scanf(" %c", &choice); 
    }

    // Display the correct number of positive and negative integers
    printf("\n--- Final Count ---");
    printf("\nPositive integers: %d", pcount);
    printf("\nNegative integers: %d\n", ncount);
    return 0;
}