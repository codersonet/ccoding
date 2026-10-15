#include <stdio.h>

int main() {
    int n, m;       // initialising number of elements in arrays A and B
    printf("Enter the number of elements in array A: ");
    scanf("%d", &n);
    printf("Enter the number of elements in array B: ");
    scanf("%d", &m);

    int A[n], B[m], merged[n + m];          // initialising arrays A, B and merged array
    printf("Enter elements of array A in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter elements of array B in ascending order:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0, k = 0;            // initialising indices for arrays A, B and merged array
    while (i < n && j < m) {            // merging arrays A and B into merged array
        if (A[i] < B[j]) {
            merged[k++] = A[i++];
        } else {
            merged[k++] = B[j++];
        }
    }

    while (i < n) {                     // adding remaining elements of array A to merged array
        merged[k++] = A[i++];
    }

    while (j < m) {                     // adding remaining elements of array B to merged array
        merged[k++] = B[j++];
    }

    printf("Merged sorted array is:\n");            // printing merged sorted array
    for (int l = 0; l < n + m; l++) {
        printf("%d ", merged[l]);
    }
    printf("\n");

    return 0;
}