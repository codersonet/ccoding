#include <stdio.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[20];
    float marks;
} Student;

int main() {
    Student s;
    Student *p = &s;            /* pointer to structure */
    Student list[3];
    Student *q = list;          /* pointer to first element of array */
    int i;

    /* assigning with arrow operator */
    p->roll_no = 101;
    strcpy(p->name, "Sanidhya");
    p->marks = 88.5f;

    /* same thing can be written as (*p).member */
    printf("Using ->   : %d %s %.1f\n", p->roll_no, p->name, p->marks);
    printf("Using (*p) : %d %s %.1f\n", (*p).roll_no, (*p).name, (*p).marks);

    /* operations on individual members through pointer */
    p->marks = p->marks + 5;    /* add grace marks */
    p->roll_no++;               /* increase roll number */
    printf("After changes: %d %s %.1f\n", p->roll_no, p->name, p->marks);

    /* reading a member from keyboard using pointer */
    printf("\nEnter new marks: ");
    scanf("%f", &p->marks);
    printf("Marks now = %.1f\n", p->marks);

    /* pointer with array of structures: q + i points to i-th element */
    for (i = 0; i < 3; i++) {
        printf("\nStudent %d roll no: ", i + 1);
        scanf("%d", &(q + i)->roll_no);
        printf("Name: ");
        scanf(" %19[^\n]", (q + i)->name);
        printf("Marks: ");
        scanf("%f", &(q + i)->marks);
    }
    printf("\n--- List ---\n");
    for (i = 0; i < 3; i++)
        printf("%d %s %.1f\n", (q + i)->roll_no, (q + i)->name, (q + i)->marks);
    return 0;
}
