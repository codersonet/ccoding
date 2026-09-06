/* Write a program in ‘C’ to calculate the area of the circle and parabola with the following
objective:
i. Taking input from the user
ii. Clearly informing the user what value to be inputted
iii. Define the name of variables/constants using proper names (as per the principle of good programming skills)
iv. The program should be well commented on.
v. Output should be user-friendly.
vi. Use the ‘while’ loop to repeat the program input-output.
vii. Use ‘\t’ and ‘\n’ to print output. */

#include <stdio.h>
#include <math.h>
#define PI 3.14159 // Define the value of PI as a constant
int main(){
    char choice; // Declare a character variable to store the user's choice
    do {
        float radius=0, area_circle; // Declare variables for radius and area of the circle
        float a=0, x=0; // Declare variables for coefficients of the parabola
        float y, area_parabola; // Declare variables for coefficients and area of the parabola

        printf("Enter the radius of the circle: "); // Prompt user for radius input
        scanf("%f", &radius); // Read the radius value from user input
        area_circle = PI * radius * radius; // Calculate the area of the circle
        printf("The area of the circle with radius %.2f is: %.2f\n", radius, area_circle); // Print the area of the circle

        printf("Enter for the parabola (y^2 = 4ax) => a\t&\tx: "); // Prompt user for parabola coefficients
        scanf("%f %f", &a, &x); // Read the coefficient a and x from user input
        y = 2 * sqrt(a * x); // Calculate the y value
        area_parabola =(2.0/3.0) * 2*y*x; // Calculate the area of the parabola with y-axis
        printf("The area of the parabola is with y-axis is: %.2f\n", area_parabola); // Print the area of the parabola

        printf("Do you want to perform another calculation? (y/n): "); // Ask user if they want to repeat
        scanf(" %c", &choice); // Read user's choice
    } while(choice == 'y' || choice == 'Y'); // Repeat if user chooses 'y' or 'Y'

    return 0; // Return 0 to indicate successful execution
}