#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_VALUE 1000000

// Store a matrix's size and its values in one structure.
typedef struct {
    int rows;
    int cols;
    long long values[MAX_SIZE][MAX_SIZE];
} Matrix;

// Read and validate one integer from a complete line of input.
static bool read_integer(const char *prompt, long long min, long long max,
                         long long *value)
{
    char line[128];

    for (;;) {
        char *end;
        long long parsed;

        // Ask for one complete line so invalid input can be retried safely.
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return false;
        }

        // Remove extra characters if the entered line is too long.
        if (strchr(line, '\n') == NULL && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // Discard the rest of an overlong input line.
            }
            printf("Input is too long. Please try again.\n");
            continue;
        }

        // Convert the line and check that it contains only an allowed integer.
        errno = 0;
        parsed = strtoll(line, &end, 10);
        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (end == line || *end != '\0' || errno == ERANGE ||
            parsed < min || parsed > max) {
            printf("Invalid input. Enter an integer from %lld to %lld.\n",
                   min, max);
            continue;
        }

        // Return the validated value to the calling function.
        *value = parsed;
        return true;
    }
}

// Read a dimension within the supported matrix size.
static bool read_dimension(const char *prompt, int *dimension)
{
    long long value;

    if (!read_integer(prompt, 1, MAX_SIZE, &value)) {
        return false;
    }

    // Save the validated dimension as an int.
    *dimension = (int)value;
    return true;
}

// Read matrix dimensions and all of its elements.
static bool read_mat(Matrix *matrix)
{
    char prompt[80];

    if (!read_dimension("Enter the number of rows (1-10): ", &matrix->rows) ||
        !read_dimension("Enter the number of columns (1-10): ", &matrix->cols)) {
        return false;
    }

    // Read every element using its row and column position.
    printf("Enter each matrix element separately when prompted.\n");
    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            long long value;

            snprintf(prompt, sizeof(prompt),
                     "Element [%d][%d] (-1000000 to 1000000): ",
                     row + 1, col + 1);
            if (!read_integer(prompt, -MAX_VALUE, MAX_VALUE, &value)) {
                return false;
            }
            matrix->values[row][col] = value;
        }
    }

    return true;
}

// Display a matrix in rows and columns.
static void print_mat(const Matrix *matrix)
{
    for (int row = 0; row < matrix->rows; row++) {
        for (int col = 0; col < matrix->cols; col++) {
            // Print each row on its own line.
            printf("%8lld", matrix->values[row][col]);
        }
        printf("\n");
    }
}

// Read two compatible matrices, add them, and display the result.
static bool add_mat(void)
{
    Matrix first, second, result;

    printf("First matrix:\n");
    if (!read_mat(&first)) {
        return false;
    }
    printf("Second matrix:\n");
    if (!read_mat(&second)) {
        return false;
    }

    if (first.rows != second.rows || first.cols != second.cols) {
        printf("Addition requires matrices with the same dimensions.\n");
        return true;
    }

    // Add elements that occupy the same row and column.
    result.rows = first.rows;
    result.cols = first.cols;
    for (int row = 0; row < result.rows; row++) {
        for (int col = 0; col < result.cols; col++) {
            result.values[row][col] =
                first.values[row][col] + second.values[row][col];
        }
    }

    printf("Sum:\n");
    print_mat(&result);
    return true;
}

// Read two compatible matrices, multiply them, and display the result.
static bool multiply_mat(void)
{
    Matrix first, second, result = {0};

    printf("First matrix:\n");
    if (!read_mat(&first)) {
        return false;
    }
    printf("Second matrix:\n");
    if (!read_mat(&second)) {
        return false;
    }

    if (first.cols != second.rows) {
        printf("Multiplication requires the first matrix's column count "
               "to equal the second matrix's row count.\n");
        return true;
    }

    // Each result element is the sum of one row-column pair of products.
    result.rows = first.rows;
    result.cols = second.cols;
    for (int row = 0; row < result.rows; row++) {
        for (int col = 0; col < result.cols; col++) {
            for (int k = 0; k < first.cols; k++) {
                result.values[row][col] +=
                    first.values[row][k] * second.values[k][col];
            }
        }
    }

    printf("Product:\n");
    print_mat(&result);
    return true;
}

// Read a matrix, transpose it, and display the transposed matrix.
static bool trasp_mat(void)
{
    Matrix matrix, transpose;

    if (!read_mat(&matrix)) {
        return false;
    }

    transpose.rows = matrix.cols;
    transpose.cols = matrix.rows;
    // Swap row and column positions to form the transpose.
    for (int row = 0; row < matrix.rows; row++) {
        for (int col = 0; col < matrix.cols; col++) {
            transpose.values[col][row] = matrix.values[row][col];
        }
    }

    printf("Transpose:\n");
    print_mat(&transpose);
    return true;
}

// Read a square matrix and report whether it is upper triangular.
static bool uptr_mat(void)
{
    Matrix matrix;
    long long sum = 0;
    bool is_upper = true;

    if (!read_mat(&matrix)) {
        return false;
    }
    if (matrix.rows != matrix.cols) {
        printf("A triangular matrix must be square.\n");
        return true;
    }

    // Sum all entries and check that entries below the diagonal are zero.
    for (int row = 0; row < matrix.rows; row++) {
        for (int col = 0; col < matrix.cols; col++) {
            sum += matrix.values[row][col];
            if (row > col && matrix.values[row][col] != 0) {
                is_upper = false;
            }
        }
    }

    if (is_upper) {
        printf("The matrix is upper triangular. Sum of all elements: %lld\n",
               sum);
    } else {
        printf("The matrix is not upper triangular.\n");
    }
    return true;
}

// Read a square matrix and report whether it is lower triangular.
static bool lowtr_mat(void)
{
    Matrix matrix;
    long long sum = 0;
    bool is_lower = true;

    if (!read_mat(&matrix)) {
        return false;
    }
    if (matrix.rows != matrix.cols) {
        printf("A triangular matrix must be square.\n");
        return true;
    }

    // Sum all entries and check that entries above the diagonal are zero.
    for (int row = 0; row < matrix.rows; row++) {
        for (int col = 0; col < matrix.cols; col++) {
            sum += matrix.values[row][col];
            if (row < col && matrix.values[row][col] != 0) {
                is_lower = false;
            }
        }
    }

    if (is_lower) {
        printf("The matrix is lower triangular. Sum of all elements: %lld\n",
               sum);
    } else {
        printf("The matrix is not lower triangular.\n");
    }
    return true;
}

// Present the menu and dispatch each operation to its function.
int main(void)
{
    long long choice;

    // Keep showing the menu until the user selects Exit or input ends.
    for (;;) {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Read and print two matrices\n");
        printf("2. Print a matrix\n");
        printf("3. Add two matrices\n");
        printf("4. Multiply two matrices\n");
        printf("5. Transpose a matrix\n");
        printf("6. Check upper triangular matrix and sum\n");
        printf("7. Check lower triangular matrix and sum\n");
        printf("0. Exit\n");

        if (!read_integer("Choose an operation: ", 0, 7, &choice)) {
            printf("\nInput ended. Exiting.\n");
            return 0;
        }

        // Call the function that matches the user's menu choice.
        switch (choice) {
            case 1: {
                // Read and then display both matrices.
                Matrix first, second;
                printf("First matrix:\n");
                if (!read_mat(&first)) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                printf("Second matrix:\n");
                if (!read_mat(&second)) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                printf("First matrix:\n");
                print_mat(&first);
                printf("Second matrix:\n");
                print_mat(&second);
                break;
            }
            case 2: {
                // Read and display one matrix.
                Matrix matrix;
                if (!read_mat(&matrix)) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                printf("Matrix:\n");
                print_mat(&matrix);
                break;
            }
            case 3:
                if (!add_mat()) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                break;
            case 4:
                if (!multiply_mat()) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                break;
            case 5:
                if (!trasp_mat()) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                break;
            case 6:
                if (!uptr_mat()) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                break;
            case 7:
                if (!lowtr_mat()) {
                    printf("\nInput ended. Exiting.\n");
                    return 0;
                }
                break;
            case 0:
                printf("Goodbye.\n");
                return 0;
        }
    }
}
