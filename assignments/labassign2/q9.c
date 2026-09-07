/* Analyse the following program and write comments. (Schuam’s
outlines/4ed/pg.4.37/Q4.8)p
# include <stdio.h>
int main() {
int x=20, y=20, z=20;
x==y=z;
printf("%d", x);
} */

#include <stdio.h>
int main() {
    int x = 20, y = 20, z = 20; // Declare three integer variables and initialize them to 20.
    x == y = z; // This line is a comparison operation, but it does not change the value of x. It evaluates to true (1) but is not assigned to any variable.
    printf("%d", x); // Print the value of x, which remains 20.
    return 0; // Return 0 to indicate
}
/*x==y is evalutaed first and returns 1 (true) since x and y are equal.
 Then 1=z is evaluated, which is false (0) since z is 20. However, 
 this result is not assigned to any variable, so x remains unchanged at 20.*/
 