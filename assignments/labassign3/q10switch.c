/* importing libararies */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* program to check the roots of any quadratic equation */
int rootsQuadratic(){
    int discriminant;
    double a,b,c,D;        //initalizing coeff and dicriminant of quadratic
    double req, rd1, rd2, lr, realpart, imgpart;    //intialising variables to store roots for different condition
    printf("Enter coefficient of quadratic (ax^2+bx+c=0): ");
    scanf("%d %d %d", &a, &b, &c);      // assigning value to the variables
    printf("Given Qudratic equation is %dx^2+%dx+%d=0\n", a, b, c);
    if (a == 0 && b == 0) {
        printf("No solution, a and b can not both be zero.\n");
    }
    else if (a == 0) {
        lr = -c / b; // Linear case
        printf("Linear equation: %.6lf\n", lr);
    }
    else {
        D = b*b - 4*a*c;                    //calculating discrimant of quadratic
        if (D > 0) {
            discriminant = 1;
        }
        else if (D == 0) {
            discriminant = 0;
        }
        else {
            discriminant = -1;
        }

        switch (discriminant) {
            case 1:
                rd1 = (-b + sqrt(D)) / (2 * a);      // 1st root calculation & assigning to variable rd1
                rd2 = (-b - sqrt(D)) / (2 * a);      // 2nd root calculation & assigning to variable rd2
                printf("D>0: Real and Distinct roots: %.6lf, %.6lf\n", rd1, rd2);
                break;
            case 0:
                req = -b / (2 * a);                  // equal roots calculation & assigning to variable req
                printf("D=0: Real and equal roots: %.6lf\n", req);
                break;
            default:
                realpart = -b / (2 * a);
                imgpart = sqrt(-D) / (2 * a);
                printf("D<0: Imaginary roots: %.6lf + %.6lfi, %.6lf - %.6lfi\n", realpart, imgpart, realpart, imgpart); // displaying the imaginary roots case
                break;
        }
    }
    return 0;                           // returning zero value after successful execution
}

int main(){
    char choice = 'y';                        //initializing variable to store user choice
    do{
        rootsQuadratic();                   //calling the function to check the roots of quadratic equation
        printf("Do you want to check another quadratic equation? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    return 0;                           //returning zero value after successful executuion
}