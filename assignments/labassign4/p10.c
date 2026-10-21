#include <stdio.h>
#include <string.h>

int main(){
    char sky[18] = "Sky is the limit.";
    printf("%s\n", sky);                        // print the entire string
    printf("%25.10s\n", sky);                   // print first 10 characters of the string with a width of 25
    printf("%c\n", sky[0]);                     // print first character of the string
    for(int i=0;sky[i]!= '.';i++)               // print characters until a period is encountered
        printf("%c", sky[i]);
    printf("\n");
    for(int i =0; sky[i]!='\0';i++)             // print ASCII values of characters
        printf("%d ", sky[i]);
    printf("\n");
    for(int i=0; i <= strlen(sky); i++)         // print characters in reverse order
        printf("%c", sky[strlen(sky)-i]);
    printf("\n");   
    printf("%c\n", sky[10+5]);                  // print the character at index 15
    printf("\n");
    for(int i=0; i <= strlen(sky); i++)         // print characters by character until the null terminator is reached
        printf("%c\n", sky[i]);
    printf("%c\n", sky[10+5]);
}
