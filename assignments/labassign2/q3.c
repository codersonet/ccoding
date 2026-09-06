/* A ‘C’ program contains the following statements.
#include <stdio.h>
int a, b;
float x, y;
Suppose the value 12 is to be entered into the computer and assigned to a, -8 assigned
to b, 0.011 assigned to x and -2.2 x 10^6 assigned to y. Show the input data might most
conveniently be entered for each of the following scanf functions
a) scanf (“%d %d %f %f”, &a, &b, &x, &y);
b) scanf (“%d %d %e %e”, &a, &b, &x, &y);
c) scanf (“%2d %2d %5f %6e”, &a, &b, &x, &y);
d) scanf (“%3d %3d %8f %8e”, &a, &b, &x, &y);
Enter the input and for each input and print the corresponding output. */

#include <stdio.h>
int main() {
    int a=0, b=0; // Declare integer variables a and b
    float x=0.0, y=0.0; // Declare float variables x and y
    printf("Enter values for a, b, x, y: ");
    scanf("%d %d %f %f", &a, &b, &x, &y); // Read input values for a, b, x, and y
    printf("You entered: a = %d, b = %d, x = %f, y = %f\n", a, b, x, y); // Print the entered values with appropriate format specifiers
    
    printf("Enter values for a, b, x, y: ");
    scanf("%d %d %e %e", &a, &b, &x, &y); 
    printf("You entered: a = %d, b = %d, x = %e, y = %e\n", a, b, x, y);
    
    printf("Enter values for a, b, x, y: ");
    scanf("%2d %2d %5f %6e", &a, &b, &x, &y);
    printf("You entered: a = %d, b = %d, x = %5f, y = %6e\n", a, b, x, y);
    
    printf("Enter values for a, b, x, y: ");
    scanf("%3d %3d %8f %8e", &a, &b, &x, &y);
    printf("You entered: a = %d, b = %d, x = %8f, y = %8e\n", a, b, x, y);
    return 0; // Return 0 to indicate successful execution
}
