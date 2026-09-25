/* importing libararies */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* program to check the roots of any quadratic equation */
int main(){
    int a,b,c,D;        //initalizing coeff and dicriminant of quadratic
    float eqr, rd1, rd2;    //intialising variables to store roots for different condition
    printf("Enter coefficient of quadratic (ax^2+bx+c=0): ");
    scanf("%d %d %d", &a, &b, &c);      // assigning value to the variables
    printf("Given Qudratic equation is %dx^2+%db+%d=0\n", a, b, c);
    D = b*b - 4*a*c;                    //calculating discrimant of quadratic
    if(D==0){
        eqr = -b/(2*a);                 //equal roots calculation & assinging to variable eqr
        printf("D=0: Real and equal roots: %.2f\n", eqr);
    }
    else if(D>0){
        rd1= (-b+sqrt(D))/(2*a);        //1st root calculation & assinging to variable eqr
        rd1= (-b-sqrt(D))/(2*a);        //2nd root calculation & assinging to variable eqr
        printf("D>0: Real and Distinct roots: %.2f, %.2f\n", rd1, rd2);
    }                                       
    else{                               
        printf("D<0: Imaginary roots\n"); //displaying the imaginary roots case
    }                                   
    return 0;                           //returning zero value after successful executuion
}