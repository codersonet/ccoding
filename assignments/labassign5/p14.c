/* Function tree:
   main
   |-- show_menu
   |-- add_record
   |     |-- read_person
   |           |-- read_address
   |           |-- read_qualifications
   |-- print_by_index
   |     |-- print_person
   |-- print_by_name
   |     |-- print_person
   |-- show_memory
   Pointers to structure are used everywhere and records are stored
   in dynamic memory, so memory grows only as records are added. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUAL 5

typedef struct {
    char name[40];
    char house_no[10];
    char street[30];
    char district[30];
    char city[30];
    char country[30];
} Address;

typedef struct {
    char q_name[20];      /* e.g. 10th, 12th, B.Tech */
    char board[40];       /* board / university */
    float marks;
    char division[15];
} Qualification;

typedef struct {
    Address address;
    int num_qual;
    Qualification qual[MAX_QUAL];
} Person;

void read_address(Address *a) {
    printf("Name: ");
    scanf(" %39[^\n]", a->name);
    printf("House number: ");
    scanf(" %9[^\n]", a->house_no);
    printf("Street: ");
    scanf(" %29[^\n]", a->street);
    printf("District: ");
    scanf(" %29[^\n]", a->district);
    printf("City: ");
    scanf(" %29[^\n]", a->city);
    printf("Country: ");
    scanf(" %29[^\n]", a->country);
}

void read_qualifications(Person *p) {
    int i;
    do {
        printf("Number of qualifications (1 to %d): ", MAX_QUAL);
        scanf("%d", &p->num_qual);
    } while (p->num_qual < 1 || p->num_qual > MAX_QUAL);

    for (i = 0; i < p->num_qual; i++) {
        printf("Qualification %d name: ", i + 1);
        scanf(" %19[^\n]", p->qual[i].q_name);
        printf("Board/University: ");
        scanf(" %39[^\n]", p->qual[i].board);
        printf("Marks: ");
        scanf("%f", &p->qual[i].marks);
        printf("Division: ");
        scanf(" %14[^\n]", p->qual[i].division);
    }
}

void read_person(Person *p) {
    read_address(&p->address);
    read_qualifications(p);
}

/* adds one record at the end, growing the array with realloc */
void add_record(Person **book, int *count) {
    Person *temp = realloc(*book, (*count + 1) * sizeof(Person));
    if (temp == NULL) {
        printf("Not enough memory!\n");
        return;
    }
    *book = temp;
    read_person(&(*book)[*count]);
    (*count)++;
}

void print_person(const Person *p) {
    int i;
    printf("\nName    : %s\n", p->address.name);
    printf("Address : %s, %s, %s, %s, %s\n", p->address.house_no,
           p->address.street, p->address.district, p->address.city,
           p->address.country);
    printf("Qualifications:\n");
    for (i = 0; i < p->num_qual; i++)
        printf("  %-10s %-25s %.2f  %s\n", p->qual[i].q_name,
               p->qual[i].board, p->qual[i].marks, p->qual[i].division);
}

void print_by_index(const Person *book, int count) {
    int index;
    printf("Enter record index (1 to %d): ", count);
    scanf("%d", &index);
    if (index < 1 || index > count)
        printf("Invalid index.\n");
    else
        print_person(&book[index - 1]);
}

void print_by_name(const Person *book, int count) {
    char name[40];
    int i, found = 0;
    printf("Enter name: ");
    scanf(" %39[^\n]", name);
    for (i = 0; i < count; i++) {
        if (strcmp(book[i].address.name, name) == 0) {
            print_person(&book[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No record found.\n");
}

void show_memory(int count) {
    printf("Size of one record : %zu bytes\n", sizeof(Person));
    printf("Records stored     : %d\n", count);
    printf("Total memory       : %zu bytes\n", count * sizeof(Person));
}

void show_menu() {
    printf("\n===== INFO BOOK =====\n");
    printf("1. Add record\n2. Print by index\n3. Print by name\n");
    printf("4. Memory required\n0. Exit\nChoice: ");
}

int main() {
    Person *book = NULL;   /* starts empty */
    int count = 0, choice;

    do {
        show_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_record(&book, &count); break;
            case 2: print_by_index(book, count); break;
            case 3: print_by_name(book, count); break;
            case 4: show_memory(count); break;
            case 0: break;
            default: printf("Wrong choice.\n");
        }
    } while (choice != 0);

    free(book);
    return 0;
}
