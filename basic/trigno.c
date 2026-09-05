#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846 // for more precision, you can use a more precise value of PI
int main(){
    float x;
    printf("Enter an angle in degrees: ");
    scanf("%f", &x);
    printf("sin(%f) = %.2f\n", x, sin(x * PI / 180)); //first %f associated with x and second %f associated with sin(x * PI / 180)
    printf("cos(%f) = %.2f\n", x, cos(x * PI / 180));
    printf("tanh(%f) = %.2f\n", x, tanh(x * PI / 180));
    printf("tan(%f) = %.2f\n", x, tan(x * PI / 180));
    return 0;
}