#include <stdio.h>

typedef struct {
    int id;
    float marks;
    char grade;
    double fee;
} StructData;

typedef union {
    int id;
    float marks;
    char grade;
    double fee;
} UnionData;

int main() {
    StructData s;
    UnionData u;

    printf("Sum of sizes of members = %zu bytes\n",
           sizeof(int) + sizeof(float) + sizeof(char) + sizeof(double));
    printf("Size of structure       = %zu bytes\n", sizeof(s));
    printf("Size of union           = %zu bytes\n", sizeof(u));

    /* structure: every member has its own memory
       (size can be more than the sum because of padding) */
    /* union: all members share the same memory,
       so size = size of the biggest member (double) */

    /* proof that union members share memory */
    u.id = 65;
    printf("\nAfter u.id = 65     : id = %d\n", u.id);
    u.grade = 'A';
    printf("After u.grade = 'A' : id = %d, grade = %c\n", u.id, u.grade);
    u.fee = 5000.75;
    printf("After u.fee = 5000.75 : fee = %.2f, id = %d (garbage, overwritten)\n",
           u.fee, u.id);
    return 0;
}
