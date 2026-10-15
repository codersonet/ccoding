#include <stdio.h>
#include <string.h>
#define size 10


int occurence(){
    int choice, count = 0, arr1[size];
    char cchoice, arr2[size];

    printf("Select array type (1 for int, 2 for char): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            for(int i = 0; i < size; i++){
                printf("Enter element %d: ", i + 1);
                scanf("%d", &arr1[i]);
            }
            for(int i = 0; i < size; i++){
                printf("%d ", arr1[i]);
            }
            printf("\n");

            printf("Enter the number to search for: ");
            scanf("%d", &choice);
            for(int i = 0; i < size; i++){
                if(arr1[i] == choice)
                    count++;              
            }
            if(count > 0)
                printf("Frequency of number %d is %d\n", choice, count);
            break;  
        case 2:
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
            for(int i = 0; i < size; i++){
                if(arr2[i] == cchoice)
                    ++count;
            }
            if(count > 0)
            printf("Frequency of character %c is %d\n", cchoice, count);
            break;
        default:
            printf("Invalid choice.\n");
    }
    count = 0;
    return 0;
}

int main() {
    char choice;
    do{
        occurence();
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    return 0;
}
