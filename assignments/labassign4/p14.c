#include <stdio.h>
#include "mystring.h"

// Read a complete line, including spaces, within the supported size.
int read_string(const char prompt[], char text[])
{
    int ch;

    while (1) {
        int i = 0;
        printf("%s", prompt);
        if (fgets(text, MYSTRING_MAX, stdin) == NULL) {
            return 0;
        }

        while (text[i] != '\0' && text[i] != '\n') {
            i++;
        }
        if (text[i] == '\n') {
            text[i] = '\0';
            return 1;
        }

        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            return 1;
        }

        while (ch != '\n' && ch != EOF) {
            ch = getchar();
        }
        printf("String is too long. Enter fewer than %d characters.\n",
               MYSTRING_MAX);
    }
}

// Remove the rest of the menu input line after reading its number.
void clear_input_line(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

// Display the menu and run the selected string operation.
int main(void)
{
    int choice;
    char first[MYSTRING_MAX];
    char second[MYSTRING_MAX];
    char result[MYSTRING_MAX * 2];

    while (1) {
        printf("\n--- String Operations ---\n");
        printf("1. Find string length\n");
        printf("2. Copy a string\n");
        printf("3. Join two strings\n");
        printf("4. Compare two strings\n");
        printf("5. Reverse a string\n");
        printf("6. Search for a substring\n");
        printf("7. Count vowels and consonants\n");
        printf("8. Split a string into words\n");
        printf("0. Exit\n");
        printf("Choose an operation: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a menu number.\n");
            if (feof(stdin)) {
                return 0;
            }
            clear_input_line();
            continue;
        }
        clear_input_line();

        switch (choice) {
            case 1:
                if (!read_string("Enter a string: ", first)) return 0;
                printf("Length: %d\n", my_strlen(first));
                break;

            case 2:
                if (!read_string("Enter a string to copy: ", first)) return 0;
                my_strcopy(second, first);
                printf("Copied string: %s\n", second);
                break;

            case 3:
                if (!read_string("Enter the first string: ", first)) return 0;
                if (!read_string("Enter the second string: ", second)) return 0;
                my_strcopy(result, first);
                my_strconcat(result, second);
                printf("Joined string: %s\n", result);
                break;

            case 4: {
                int comparison;
                if (!read_string("Enter the first string: ", first)) return 0;
                if (!read_string("Enter the second string: ", second)) return 0;
                comparison = my_strcompare(first, second);
                if (comparison == 0) {
                    printf("The strings are equal.\n");
                } else if (comparison < 0) {
                    printf("The first string is lexicographically smaller.\n");
                } else {
                    printf("The second string is lexicographically smaller.\n");
                }
                break;
            }

            case 5:
                if (!read_string("Enter a string: ", first)) return 0;
                my_strreverse(first);
                printf("Reversed string: %s\n", first);
                break;

            case 6: {
                int position;
                if (!read_string("Enter the main string: ", first)) return 0;
                if (!read_string("Enter the substring to find: ", second)) return 0;
                position = my_strsearch(first, second);
                if (position == 0) {
                    printf("Substring not found.\n");
                } else {
                    printf("Substring starts at position %d.\n", position);
                }
                break;
            }

            case 7: {
                int vowels, consonants;
                if (!read_string("Enter a string: ", first)) return 0;
                my_count_vowels_consonants(first, &vowels, &consonants);
                printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
                break;
            }

            case 8:
                if (!read_string("Enter a string: ", first)) return 0;
                my_strtokenize(first);
                break;

            case 0:
                printf("Goodbye.\n");
                return 0;

            default:
                printf("Choose a number from 0 to 8.\n");
        }
    }
}