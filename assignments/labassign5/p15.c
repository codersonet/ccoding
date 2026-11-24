/* Vector operations */
#include <stdio.h>

#define MAX_SIZE 30

typedef struct {
    int data[MAX_SIZE];
    int size;
} Vector;

/* (a) create a vector */
Vector create_vector() {
    Vector v;
    int i;
    do {
        printf("Number of elements (1-%d): ", MAX_SIZE);
        scanf("%d", &v.size);
    } while (v.size < 1 || v.size > MAX_SIZE);
    for (i = 0; i < v.size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &v.data[i]);
    }
    return v;
}

/* (b) search: returns position of the value, -1 if not found */
int find(Vector v, int val) {
    int i;
    for (i = 0; i < v.size; i++)
        if (v.data[i] == val)
            return i;
    return -1;
}

/* (c) multiply by scalar */
Vector multiply(Vector v, int k) {
    int i;
    for (i = 0; i < v.size; i++)
        v.data[i] *= k;
    return v;
}

/* (d) display as (10,20,30) */
void display(Vector v) {
    int i;
    printf("(");
    for (i = 0; i < v.size; i++) {
        if (i > 0)
            printf(",");
        printf("%d", v.data[i]);
    }
    printf(")\n");
}

/* (f) add two vectors, size 0 means sizes were different */
Vector add(Vector a, Vector b) {
    Vector s;
    int i;
    s.size = 0;
    if (a.size != b.size)
        return s;
    s.size = a.size;
    for (i = 0; i < s.size; i++)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

int main() {
    Vector v = create_vector(), w, sum;
    int ch, pos, old_val, k;

    do {
        printf("\n1.Modify 2.Multiply 3.Display 4.Size 5.Add 0.Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Value to search: ");
            scanf("%d", &old_val);
            pos = find(v, old_val);
            if (pos == -1)
                printf("Value not found.\n");
            else {
                printf("New value: ");
                scanf("%d", &v.data[pos]);
            }
        } else if (ch == 2) {
            printf("Scalar: ");
            scanf("%d", &k);
            v = multiply(v, k);
        } else if (ch == 3) {
            display(v);
        } else if (ch == 4) {   /* (e) size and memory */
            printf("Structure size: %zu bytes, memory used by elements: %zu bytes\n",
                   sizeof(Vector), v.size * sizeof(int));
        } else if (ch == 5) {
            printf("Second vector:\n");
            w = create_vector();
            sum = add(v, w);
            if (sum.size == 0)
                printf("Sizes are different.\n");
            else
                display(sum);
        }
    } while (ch != 0);
    return 0;
}
