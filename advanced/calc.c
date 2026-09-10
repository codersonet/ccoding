#include <stdio.h>

int main(void) {
    char op;
    double num1, num2, result;

    printf("Simple Calculator\n");
    printf("Enter expression (example: 10 + 5): ");

    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Unsupported operator: %c\n", op);
            return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, op, num2, result);
    return 0;
}
