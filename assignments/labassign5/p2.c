#include <stdio.h>

#define M_SIZE 30     /* max size of 1D vector */
#define DIM 20        /* 2D vector is 20 x 20 */
#define MAX_INPUT 6   /* read at most 6 values from keyboard */

typedef struct { int data[M_SIZE]; int size; } Vector1D;
typedef struct { int data[DIM][DIM]; int rows, cols; } Vector2D;

/* (a) create vectors */
Vector1D create_1d() {
    Vector1D v;
    int i;
    do {
        printf("Number of elements (1-%d): ", MAX_INPUT);
        scanf("%d", &v.size);
    } while (v.size < 1 || v.size > MAX_INPUT);
    for (i = 0; i < v.size; i++)
        scanf("%d", &v.data[i]);
    return v;
}

Vector2D create_2d() {
    Vector2D v;
    int i, j;
    do {
        printf("Rows and columns (rows*cols <= %d): ", MAX_INPUT);
        scanf("%d %d", &v.rows, &v.cols);
    } while (v.rows < 1 || v.cols < 1 || v.rows * v.cols > MAX_INPUT);
    for (i = 0; i < v.rows; i++)
        for (j = 0; j < v.cols; j++)
            scanf("%d", &v.data[i][j]);
    return v;
}

/* (b) search: returns position of the value, -1 if not found.
   For 2D the position is counted row by row (row = pos / cols, col = pos % cols) */
int find_1d(Vector1D v, int val) {
    int i;
    for (i = 0; i < v.size; i++)
        if (v.data[i] == val)
            return i;
    return -1;
}

int find_2d(Vector2D v, int val) {
    int i, j;
    for (i = 0; i < v.rows; i++)
        for (j = 0; j < v.cols; j++)
            if (v.data[i][j] == val)
                return i * v.cols + j;
    return -1;
}

/* (c) multiply by scalar */
Vector1D multiply_1d(Vector1D v, int k) {
    int i;
    for (i = 0; i < v.size; i++)
        v.data[i] *= k;
    return v;
}

Vector2D multiply_2d(Vector2D v, int k) {
    int i, j;
    for (i = 0; i < v.rows; i++)
        for (j = 0; j < v.cols; j++)
            v.data[i][j] *= k;
    return v;
}

/* (d) display in matrix form */
void display_1d(Vector1D v) {
    int i;
    printf("[ ");
    for (i = 0; i < v.size; i++)
        printf("%d ", v.data[i]);
    printf("]\n");
}

void display_2d(Vector2D v) {
    int i, j;
    for (i = 0; i < v.rows; i++) {
        printf("[ ");
        for (j = 0; j < v.cols; j++)
            printf("%d ", v.data[i][j]);
        printf("]\n");
    }
}

/* (f) add two vectors, size/rows is set to 0 if dimensions differ */
Vector1D add_1d(Vector1D a, Vector1D b) {
    Vector1D s;
    int i;
    s.size = 0;
    if (a.size != b.size)
        return s;
    s.size = a.size;
    for (i = 0; i < s.size; i++)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

Vector2D add_2d(Vector2D a, Vector2D b) {
    Vector2D s;
    int i, j;
    s.rows = 0;
    if (a.rows != b.rows || a.cols != b.cols)
        return s;
    s.rows = a.rows;
    s.cols = a.cols;
    for (i = 0; i < s.rows; i++)
        for (j = 0; j < s.cols; j++)
            s.data[i][j] = a.data[i][j] + b.data[i][j];
    return s;
}

void menu_1d() {
    Vector1D v = create_1d(), w, sum;
    int ch, pos, old, k;
    do {
        printf("\n1.Modify 2.Multiply 3.Display 4.Size 5.Add 0.Back: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Value to search: ");
            scanf("%d", &old);
            pos = find_1d(v, old);
            if (pos == -1)
                printf("Not found.\n");
            else {
                printf("New value: ");
                scanf("%d", &v.data[pos]);
            }
        } else if (ch == 2) {
            printf("Scalar: ");
            scanf("%d", &k);
            v = multiply_1d(v, k);
        } else if (ch == 3)
            display_1d(v);
        else if (ch == 4) /* (e) size of structure and memory used */
            printf("Structure: %zu bytes, elements used: %zu bytes\n",
                   sizeof(Vector1D), v.size * sizeof(int));
        else if (ch == 5) {
            printf("Second vector:\n");
            w = create_1d();
            sum = add_1d(v, w);
            if (sum.size == 0)
                printf("Sizes differ.\n");
            else
                display_1d(sum);
        }
    } while (ch != 0);
}

void menu_2d() {
    Vector2D v = create_2d(), w, sum;
    int ch, pos, old, k;
    do {
        printf("\n1.Modify 2.Multiply 3.Display 4.Size 5.Add 0.Back: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Value to search: ");
            scanf("%d", &old);
            pos = find_2d(v, old);
            if (pos == -1)
                printf("Not found.\n");
            else {
                printf("New value: ");
                scanf("%d", &v.data[pos / v.cols][pos % v.cols]);
            }
        } else if (ch == 2) {
            printf("Scalar: ");
            scanf("%d", &k);
            v = multiply_2d(v, k);
        } else if (ch == 3)
            display_2d(v);
        else if (ch == 4)
            printf("Structure: %zu bytes, elements used: %zu bytes\n",
                   sizeof(Vector2D), v.rows * v.cols * sizeof(int));
        else if (ch == 5) {
            printf("Second vector:\n");
            w = create_2d();
            sum = add_2d(v, w);
            if (sum.rows == 0)
                printf("Dimensions differ.\n");
            else
                display_2d(sum);
        }
    } while (ch != 0);
}

int main() {
    int ch;
    do {
        printf("\n1.1D vector 2.2D vector 0.Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
            menu_1d();
        else if (ch == 2)
            menu_2d();
    } while (ch != 0);
    return 0;
}
