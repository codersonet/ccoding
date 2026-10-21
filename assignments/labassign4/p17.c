#include <math.h>
#include <stdio.h>

#define MAX_SIZE 10
#define EPSILON 1e-9

// Use row reduction to count the independent rows (pivots) in the matrix.
int find_rank(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    int rank = 0;

    // Search each column for a pivot, starting below the previous pivot row.
    for (int col = 0; col < cols && rank < rows; col++) {
        int pivot_row = rank;
        for (int row = rank + 1; row < rows; row++) {
            if (fabs(matrix[row][col]) > fabs(matrix[pivot_row][col])) {
                pivot_row = row;
            }
        }

        // Ignore this column if all remaining values are effectively zero.
        if (fabs(matrix[pivot_row][col]) < EPSILON) {
            continue;
        }

        // Move the pivot row into the next rank position.
        if (pivot_row != rank) {
            for (int j = 0; j < cols; j++) {
                double temporary = matrix[rank][j];
                matrix[rank][j] = matrix[pivot_row][j];
                matrix[pivot_row][j] = temporary;
            }
        }

        // Eliminate the values below this pivot.
        for (int row = rank + 1; row < rows; row++) {
            double factor = matrix[row][col] / matrix[rank][col];
            for (int j = col; j < cols; j++) {
                matrix[row][j] -= factor * matrix[rank][j];
            }
        }

        rank++;
    }

    return rank;
}

int main(void)
{
    double matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Read and validate the matrix dimensions.
    printf("Enter the number of rows and columns (1-%d): ", MAX_SIZE);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE) {
        printf("Invalid dimensions. Enter row and column counts from 1 to %d.\n",
               MAX_SIZE);
        return 1;
    }

    // Read each matrix value row by row.
    printf("Enter the matrix elements row by row:\n");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (scanf("%lf", &matrix[row][col]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
        }
    }

    // Find and display the matrix rank.
    printf("Rank of the matrix: %d\n", find_rank(matrix, rows, cols));
    return 0;
}