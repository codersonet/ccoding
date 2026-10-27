#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to hold library information
typedef struct {
    int num_books;
    int num_magazines;
    int num_journals;
    char librarian_name[20];
} Library;

// Function to read library details from the user
int main(void)
{
    Library lib;
    int i = 0;
    char ch;

    printf("Eneter No of Books: ");
    scanf("%d", &lib.num_books);
    
    printf("Eneter No of Magazines: ");
    scanf("%d", &lib.num_magazines);

    printf("Eneter No of Journals: ");
    scanf("%d", &lib.num_journals);

    printf("Enter Librarian Name: ");
    // Clear the newline character from the input buffer
    getchar(); 
    // Read the librarian name with spaces
    fgets(lib.librarian_name, sizeof(lib.librarian_name), stdin);
    // Remove the newline character if present
    lib.librarian_name[strcspn(lib.librarian_name, "\n")] = '\0';

    printf("\nx--- Library Details ---x\n");
    printf("Books      : %d\n", lib.num_books);
    printf("Magazines  : %d\n", lib.num_magazines);
    printf("Journals   : %d\n", lib.num_journals);
    printf("Librarian  : %s\n", lib.librarian_name);

    return 0;
}