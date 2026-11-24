/* Q7: Function to compare two structures */
#include <stdio.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[20];
    float marks;
} Student;

/* returns 1 if both structures are equal, 0 otherwise.
   Members are compared one by one (memcmp can fail because of padding). */
int compare_students(const Student *a, const Student *b) {
    if (a->roll_no != b->roll_no)
        return 0;
    if (strcmp(a->name, b->name) != 0)
        return 0;
    if (a->marks != b->marks)
        return 0;
    return 1;
}

void show_result(const char *msg, const Student *a, const Student *b) {
    printf("%-30s -> %s\n", msg,
           compare_students(a, b) ? "EQUAL" : "NOT EQUAL");
}

int main() {
    Student s1 = {1, "Sanidhya", 85.5f};
    Student s2 = {1, "Sanidhya", 85.5f};   /* same as s1 */
    Student s3 = {2, "Sanidhya", 85.5f};   /* roll no differs */
    Student s4 = {1, "Rahul", 85.5f};      /* name differs */
    Student s5 = {1, "Sanidhya", 70.0f};   /* marks differ */

    /* testing all the cases to show that function works */
    show_result("s1 vs s2 (identical)", &s1, &s2);
    show_result("s1 vs s3 (roll differs)", &s1, &s3);
    show_result("s1 vs s4 (name differs)", &s1, &s4);
    show_result("s1 vs s5 (marks differ)", &s1, &s5);
    return 0;
}
