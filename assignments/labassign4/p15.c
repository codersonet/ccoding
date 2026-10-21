#include <stdio.h>
#include <string.h>

int main(void)
{
    // Leave enough room for the original text, three appended characters, and '\0'.
    char s1[32] = "ANIL KUMAR GUPTA";
    char s2[] = "KUMAR";

    // strstr returns a pointer to the first occurrence of "KUMAR" in s1.
    char *found = strstr(s1, s2);
    if (found != NULL) {
        printf("%s\n", found);
    } else {
        printf("Substring not found.\n");
    }

    // Append the first three characters of s2 to the end of s1.
    strncat(s1, s2, 3);
    printf("%s\n", s1);

    return 0;
}