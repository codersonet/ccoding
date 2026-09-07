/* Write a program to observe the behaviour of the following Escape sequence ‘\n’, ‘\t’,
‘\b’, ‘\', ‘\\’, ‘\', ‘\a’. Write comments on the output. */

#include <stdio.h>
int main() {
    printf("Make In INDIA, For The World!\n"); // Newline escape sequence
    printf("Make In INDIA,\tFor The World!\n"); // Tab escape sequence
    printf("Make In INDIA, For The World!\b!\n"); // Backspace escape sequence
    printf("Make In INDIA, \"/For The World!\"\n"); // Double quote escape sequence
    printf("Make In INDIA, \\For The World!\\\n"); // Backslash escape sequence
    printf("Make In INDIA, \aFor The World!\n"); // Alert (bell) escape sequence
    return 0;
}