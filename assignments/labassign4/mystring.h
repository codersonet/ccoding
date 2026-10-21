#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>

#define MYSTRING_MAX 200

// Return the number of characters before the string's terminating null.
int my_strlen(const char text[])
{
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}

// Copy a string into another character array.
void my_strcopy(char destination[], const char source[])
{
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Add the source string to the end of the destination string.
void my_strconcat(char destination[], const char source[])
{
    int end = my_strlen(destination);
    int i = 0;

    while (source[i] != '\0') {
        destination[end + i] = source[i];
        i++;
    }
    destination[end + i] = '\0';
}

// Return 0 for equal strings, a negative value if first comes first, else positive.
int my_strcompare(const char first[], const char second[])
{
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0' &&
           first[i] == second[i]) {
        i++;
    }
    return (unsigned char)first[i] - (unsigned char)second[i];
}

// Reverse a string by swapping characters from its two ends.
void my_strreverse(char text[])
{
    int left = 0;
    int right = my_strlen(text) - 1;

    while (left < right) {
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
        left++;
        right--;
    }
}

// Find a substring and return its one-based starting position, or 0 if absent.
int my_strsearch(const char text[], const char substring[])
{
    int text_length = my_strlen(text);
    int sub_length = my_strlen(substring);

    if (sub_length == 0) {
        return 1;
    }

    for (int start = 0; start <= text_length - sub_length; start++) {
        int offset = 0;
        while (offset < sub_length &&
               text[start + offset] == substring[offset]) {
            offset++;
        }
        if (offset == sub_length) {
            return start + 1;
        }
    }
    return 0;
}

// Count English vowels and consonants in a string.
void my_count_vowels_consonants(const char text[], int *vowels,
                                int *consonants)
{
    *vowels = 0;
    *consonants = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char letter = text[i];
        if ((letter >= 'A' && letter <= 'Z') ||
            (letter >= 'a' && letter <= 'z')) {
            if (letter == 'a' || letter == 'e' || letter == 'i' ||
                letter == 'o' || letter == 'u' || letter == 'A' ||
                letter == 'E' || letter == 'I' || letter == 'O' ||
                letter == 'U') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

// Print each group of non-space characters as a separate token.
void my_strtokenize(char text[])
{
    int i = 0;
    int token_number = 1;

    while (text[i] != '\0') {
        while (text[i] == ' ') {
            i++;
        }
        if (text[i] == '\0') {
            break;
        }

        printf("Token %d: ", token_number++);
        while (text[i] != '\0' && text[i] != ' ') {
            putchar(text[i]);
            i++;
        }
        putchar('\n');
    }
}

#endif
