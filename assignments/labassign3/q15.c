/*
    Write a C program to input marks of five subjects: Physics, Chemistry,
    Biology, Mathematics, and Computer.
    Calculate the percentage and assign a grade based on the following rules:
    Percentage >= 90% : Grade A
    Percentage >= 80% : Grade B
    Percentage >= 70% : Grade C
    Percentage >= 60% : Grade D
    Percentage >= 40% : Grade E
    Percentage < 40%  : Grade F
*/

#include <stdio.h>

int main() {
    /* Store marks for all five subjects */
    float physics, chemistry, biology, mathematics, computer;

    /* Store overall total and percentage */
    float total, percentage;

    /* Store the final grade assigned based on percentage */
    char grade;

    /* Input marks from the user */
    printf("Enter marks for Physics, Chemistry, Biology, Mathematics and Computer: ");
    scanf("%f %f %f %f %f", &physics, &chemistry, &biology, &mathematics, &computer);

    /* Calculate total marks and percentage */
    total = physics + chemistry + biology + mathematics + computer;
    percentage = (total / 500) * 100;

    /* Decide grade using percentage ranges */
    switch ((int)percentage / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        case 5:
        case 4:
            grade = 'E';
            break;
        default:
            grade = 'F';
            break;
    }

    /* Display the computed result */
    printf("Total marks: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}