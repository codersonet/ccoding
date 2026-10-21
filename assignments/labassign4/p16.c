#include <ctype.h>
#include <stdio.h>

#define SENTENCE_SIZE 200

// Count the whitespace-separated substrings and print the third one if present.
void Num_sstr(const char *sentence)
{
    int count = 0;
    int i = 0;

    while (sentence[i] != '\0') {
        // Skip spaces between substrings.
        while (sentence[i] != '\0' && isspace((unsigned char)sentence[i])) {
            i++;
        }
        if (sentence[i] == '\0') {
            break;
        }

        count++;
        if (count == 3) {
            printf("Third substring: ");
            while (sentence[i] != '\0' &&
                   !isspace((unsigned char)sentence[i])) {
                putchar(sentence[i]);
                i++;
            }
            putchar('\n');
        } else {
            // Move to the end of this substring.
            while (sentence[i] != '\0' &&
                   !isspace((unsigned char)sentence[i])) {
                i++;
            }
        }
    }

    printf("Number of substrings: %d\n", count);
    if (count < 3) {
        printf("There is no third substring.\n");
    }
}

// Read a sentence and pass its character array to Num_sstr.
void mystr(void)
{
    char sntm[SENTENCE_SIZE];
    int i = 0;

    printf("Enter a sentence: ");
    if (fgets(sntm, sizeof(sntm), stdin) == NULL) {
        printf("Could not read the sentence.\n");
        return;
    }

    // Remove the newline added by fgets, if the sentence fits on the line.
    while (sntm[i] != '\0' && sntm[i] != '\n') {
        i++;
    }
    if (sntm[i] == '\n') {
        sntm[i] = '\0';
    }

    Num_sstr(sntm);
}

int main(void)
{
    // Start the sentence input and substring count.
    mystr();
    return 0;
}