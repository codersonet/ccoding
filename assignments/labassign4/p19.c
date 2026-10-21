#include <math.h>
#include <stdio.h>

#define MAX_SIZE 10
#define EPSILON 1e-9

int main(void)
{
    double matrix[MAX_SIZE][2 * MAX_SIZE] = {0};
    int size;

    // Read and validate the matrix order; only square matrices can have inverses.
    printf("Enter the order of the square matrix (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Enter an integer from 1 to %d.\n", MAX_SIZE);
        return 1;
    }

    // Read the matrix on the left and place the identity matrix on the right.
    printf("Enter the matrix elements row by row:\n");
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (scanf("%lf", &matrix[row][col]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
        }
        matrix[row][size + row] = 1.0;
    }

    // Apply Gauss-Jordan elimination to turn the left half into the identity.
    for (int pivot_col = 0; pivot_col < size; pivot_col++) {
        int pivot_row = pivot_col;

        // Choose the largest available pivot to improve numerical stability.
        for (int row = pivot_col + 1; row < size; row++) {
            if (fabs(matrix[row][pivot_col]) >
                fabs(matrix[pivot_row][pivot_col])) {
                pivot_row = row;
            }
        }

        // A zero pivot means the matrix is singular and has no inverse.
        if (fabs(matrix[pivot_row][pivot_col]) < EPSILON) {
            printf("The matrix is singular, so it has no inverse.\n");
            return 0;
        }

        // Swap the pivot row into position when needed.
        if (pivot_row != pivot_col) {
            for (int col = 0; col < 2 * size; col++) {
                double temporary = matrix[pivot_col][col];
                matrix[pivot_col][col] = matrix[pivot_row][col];
                matrix[pivot_row][col] = temporary;
            }
        }

        // Divide the pivot row by its pivot so the pivot becomes 1.
        double pivot = matrix[pivot_col][pivot_col];
        for (int col = 0; col < 2 * size; col++) {
            matrix[pivot_col][col] /= pivot;
        }

        // Make all other values in this pivot column zero.
        for (int row = 0; row < size; row++) {
            if (row != pivot_col) {
                double factor = matrix[row][pivot_col];
                for (int col = 0; col < 2 * size; col++) {
                    matrix[row][col] -= factor * matrix[pivot_col][col];
                }
            }
        }
    }

    // The right half now contains the inverse matrix.
    printf("Inverse matrix:\n");
    for (int row = 0; row < size; row++) {
        for (int col = size; col < 2 * size; col++) {
            printf("%10.4f", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}