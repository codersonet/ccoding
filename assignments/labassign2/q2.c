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
#include <string.h>
#include <math.h>
#define PI 3.14 // Define the value of PI as a constant

int main(){
    char input[50];
    float radius, area_circle; // Declare variables for radius and area of the circle
    float a = 0, x = 0, y = 0, area_parabola = 0; // Declare variables for parabola

    while (1) {
        printf("Enter radius of circle (type 'q' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0) {
            printf("Program exited.\n");
            break;
        }

        if (sscanf(input, "%f", &radius) != 1) {
            printf("Invalid input. Please enter a number or 'q' to quit.\n");
            continue;
        }

        area_circle = PI * radius * radius; // Calculate the area of the circle
        printf("Area of circle is %f\n", area_circle); // Print the area of the circle

        printf("Enter for parabola (y^2 = 4ax) => a and x (type 'q' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q\n") == 0 || strcmp(input, "Q\n") == 0) {
            printf("Program exited.\n");
            break;
        }

        if (sscanf(input, "%f %f", &a, &x) != 2) {
            printf("Invalid input. Please enter two numbers or 'q' to quit.\n");
            continue;
        }

        y = 2 * sqrt(a * x); // Calculate the y value
        area_parabola = (2.0 / 3.0) * 2 * y * x; // Calculate the area of the parabola with y-axis
        printf("The area of the parabola is: %.2f\n", area_parabola); // Print the area of the parabola
    }

    return 0;
}
