#include <math.h>
#include <stdio.h>

#define MAX_SIZE 10
#define EPSILON 1e-9

// Find and swap a non-zero pivot into the current row.
int swap_pivot_row(double matrix[MAX_SIZE][MAX_SIZE + 1],
                   int pivot_row, int column, int row_count)
{
    int best_row = pivot_row;

    for (int row = pivot_row + 1; row < row_count; row++) {
        if (fabs(matrix[row][column]) > fabs(matrix[best_row][column])) {
            best_row = row;
        }
    }

    if (fabs(matrix[best_row][column]) < EPSILON) {
        return 0;
    }

    if (best_row != pivot_row) {
        for (int col = 0; col <= MAX_SIZE; col++) {
            double temporary = matrix[pivot_row][col];
            matrix[pivot_row][col] = matrix[best_row][col];
            matrix[best_row][col] = temporary;
        }
    }
    return 1;
}

int main(void)
{
    double matrix[MAX_SIZE][MAX_SIZE + 1] = {0};
    int pivot_columns[MAX_SIZE];
    int equations, unknowns;
    int rank = 0;

    // A has one row per equation and one column per unknown; the last column stores B.
    printf("Enter the number of equations and unknowns (1-%d): ", MAX_SIZE);
    if (scanf("%d %d", &equations, &unknowns) != 2 ||
        equations < 1 || equations > MAX_SIZE ||
        unknowns < 1 || unknowns > MAX_SIZE) {
        printf("Invalid dimensions. Enter counts from 1 to %d.\n", MAX_SIZE);
        return 1;
    }

    // Read each equation's coefficients followed by its right-hand-side value.
    printf("Enter the coefficients of each equation, followed by its B value.\n");
    for (int row = 0; row < equations; row++) {
        printf("Equation %d (%d coefficients and then B): ", row + 1, unknowns);
        for (int col = 0; col <= unknowns; col++) {
            if (scanf("%lf", &matrix[row][col]) != 1) {
                printf("Invalid number in the system.\n");
                return 1;
            }
        }
    }

    // Use Gauss-Jordan elimination to produce pivot columns and reduced rows.
    for (int col = 0; col < unknowns && rank < equations; col++) {
        if (!swap_pivot_row(matrix, rank, col, equations)) {
            continue;
        }

        // Make the pivot equal to 1.
        double pivot = matrix[rank][col];
        for (int j = 0; j <= unknowns; j++) {
            matrix[rank][j] /= pivot;
        }

        // Eliminate this variable from every other equation.
        for (int row = 0; row < equations; row++) {
            if (row != rank) {
                double factor = matrix[row][col];
                for (int j = 0; j <= unknowns; j++) {
                    matrix[row][j] -= factor * matrix[rank][j];
                }
            }
        }

        pivot_columns[rank] = col;
        rank++;
    }

    // A zero coefficient row with a non-zero B value makes the system inconsistent.
    for (int row = 0; row < equations; row++) {
        int all_zero = 1;
        for (int col = 0; col < unknowns; col++) {
            if (fabs(matrix[row][col]) >= EPSILON) {
                all_zero = 0;
                break;
            }
        }
        if (all_zero && fabs(matrix[row][unknowns]) >= EPSILON) {
            printf("The system has no solution.\n");
            return 0;
        }
    }

    // Set free variables to zero to show one solution when infinitely many exist.
    double solution[MAX_SIZE] = {0};
    for (int row = 0; row < rank; row++) {
        solution[pivot_columns[row]] = matrix[row][unknowns];
    }

    if (rank == unknowns) {
        printf("The system has a unique solution:\n");
    } else {
        printf("The system has infinitely many solutions.\n");
        printf("One solution, with free variables set to 0, is:\n");
    }

    for (int col = 0; col < unknowns; col++) {
        printf("x%d = %.6g\n", col + 1, solution[col]);
    }

    return 0;
}