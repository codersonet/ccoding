#include <stdio.h>

int main(void)
{
	int num, pos=0, neg=0; // Declare variables to store the number, count of positive numbers, and count of negative numbers
	char choice; // Declare a variable to store the user's choice to continue or not

	do {
		printf("Enter a number: "); // Prompt the user to enter a number
		scanf("%d", &num);

		if (num > 0) // Increment the count of positive numbers if the entered number is greater than 0
			pos++;
		else if (num < 0) // Increment the count of negative numbers if the entered number is less than 0
			neg++;

		printf("Total positives: %d\n", pos);
		printf("Total negatives: %d\n", neg);
		printf("Do you want to continue? (y/n): ");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y'); // Continue the loop if the user enters 'y' or 'Y'
	return 0; // Return 0 to indicate successful execution
}
