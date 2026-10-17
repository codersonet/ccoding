#include <stdio.h>
#include <string.h>
#define size 10                     // define size of array as 10


int occurence(){                    // function to find occurence of an element in an array
    int choice, count = 0, arr1[size];
    char cchoice, arr2[size];

    printf("Select array type (1 for int, 2 for char): ");
    scanf("%d", &choice);           // user input for array type

    switch(choice){                 // switch case to select array type
        case 1:                     // case for integer array
            for(int i = 0; i < size; i++){
                printf("Enter element %d: ", i + 1);
                scanf("%d", &arr1[i]);
            }
            for(int i = 0; i < size; i++){              // print the integer array elements
                printf("%d ", arr1[i]);
            }
            printf("\n");

            printf("Enter the number to search for: ");
            scanf("%d", &choice);
            for(int i = 0; i < size; i++){              // loop to find the frequency of the number in the array
                if(arr1[i] == choice)
                    count++;                            // increment count if the number is found
            }
            if(count > 0)                               // print the frequency of the number in the array
                printf("Frequency of number %d is %d\n", choice, count);
            break;  

        case 2:                 // case for character array 
            for(int i = 0; i < size; i++){
                printf("Enter element %d: ", i + 1);
                scanf(" %c", &arr2[i]);
            }
            printf("Character array elements are: ");
            for(int i = 0; i < size; i++){
                printf("%c ", arr2[i]);
            }
            printf("\n");

            printf("Enter the character to search for: ");
            scanf(" %c", &cchoice);
            for(int i = 0; i < size; i++){              // loop to find the frequency of the character in the array 
                if(arr2[i] == cchoice)                  // increment count if the character is found
                    ++count;
            }
            if(count > 0)                               // print the frequency of the character in the array
            printf("Frequency of character %c is %d\n", cchoice, count);
            break;
            
        default:                    // default case for invalid choice
            printf("Invalid choice.\n");
    }
    count = 0;                      // reset count for next iteration
    return 0;                       // return 0 to indicate successful execution
}

int main() {                        // main function to call occurence function and loop until user chooses to exit
    char choice;
    do{
        occurence();                // call the occurence function
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');               // loop to continue the program until user chooses to exit
    return 0;
}
