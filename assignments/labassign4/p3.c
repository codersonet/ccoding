#include <stdio.h>
#include <string.h>

int isIdentity(){
        int  row, col;          // initializing the variable to store the number of rows and columns of the matrix
        printf("Enter no of rows and columns: ");
        scanf("%d %d", &row, &col);
        int matrix[row][col];
        if(row==col)            // checking if the matrix is a square matrix or not
                printf("It is a square matrix.");
        else
                printf("Not a square matrix.");

        // asking the user to enter the values of the matrix
        for(int i =1; i <= row; i++){
                for(int j=1; j <= col; j++){
                        printf("Enter value of Matrix[%d][%d]: ", i, j);
                        scanf("%d", &matrix[i][j]);
                }
        }

        // checking the identity matrix condition
        int identity = 1;
        for(int i =1; i <= row; i++){
                for(int j=1; j <= col; j++){
                        if(i==j && matrix[i][j]!=1){
                                identity = 0;
                                break;
                        }
                        else if(i!=j && matrix[i][j]!=0){
                                identity = 0;
                                break;
                        }
                }
        }

        // printing the result based on the identity matrix condition
        if(identity)
                printf("\nIt is an identity matrix.\n");
        else
                printf("\nIt is not an identity matrix.\n");
        
        // printing the matrix
        printf("\nThe matrix is: \n");
        for(int i =1; i <= row; i++){
                for(int j=1; j <= col; j++){
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }
        printf("\n");
        return 0;
}

int main(){
        char choice = 'y';              // sets choice to y by default
        while(choice == 'y' || choice == 'Y'){
                isIdentity();                 // calls the identity function
                printf("\nDo you want to run Again? (y/n) ");
                scanf(" %c", &choice);
                printf("\n");
        }
        return 0;
}
