#include <stdio.h>
#include <string.h>

int isPalindrome(){
        int vary;               // intializes the variable length of the string from the user
        printf("Enter the length of array: ");
        scanf("%d", &vary);

        if(vary<=0){            //checks if length entered is negative or zero
                printf("Oops: Invalid!\n");
                return 0;
        }

        int palindrome[vary];

        for(int i =0; i<vary; i++){
                printf("Enter value of [%d]: ", i);             // asks the values of the array
                scanf("%d", &palindrome[i]);                    // assigns the entered values to the array
        }

        int flag = 1;           // loop handles palindrome condition if true

        if(vary%2==0){          // check if the length of the array is even
                for(int i = 0; i<vary/2; i++){          // iterates till the half of array
                        if(palindrome[i] != palindrome[vary-1-i]){              //compares the corresponding indices
                                flag = 0;
                                break;
                        }
                }
        }

        else{                   // for odd length array
                for(int i = 0; i<(vary-1)/2; i++){
                        if(palindrome[i] != palindrome[vary-1-i]){
                                flag = 0;
                                break;
                        }
                }
        }
        if(flag==1)
                printf("Is Palindrome :)\n");
        else
                printf("Not a Plaindrome :(\n");
        return 0;
}

int main(){
        char choice = 'y';              // sets choice to y by default
        while(choice == 'y' || choice == 'Y'){
                isPalindrome();                 // calls the palindrome function
                printf("\nDo you want to run Again? (y/n) ");
                scanf(" %c", &choice);
                printf("\n");
        }
        return 0;
}
