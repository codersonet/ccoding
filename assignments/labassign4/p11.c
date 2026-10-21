#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void median();
void stddev();
void determinant();

int main(void){
    char choice;
    // Repeat the menu while the user chooses yes.
    do{
        int user;
        printf("x----List of Operations----x\n");
        printf("1. Median\n2. Standard Deviation\n3. Determinant\n");
        printf("What do you want to check: ");
        scanf("%d", &user);
        // Run the operation selected from the menu.
        switch(user){
            case 1:
                median();
                break;
            case 2:
                stddev();
                break;
            case 3:
                determinant();
                break;
            default:
                printf("Enter a Valid choice!!!");
        }
        printf("Do you want to run again(y/n)? ");
        scanf(" %c", &choice);
    }while(choice == 'Y' || choice == 'y');
    return 0;
}

void median(){
    // Read the array length and its integer elements.
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    int n[len];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < len; i++){
        scanf("%d", &n[i]);
    }
    // For an even length, average the two middle elements; otherwise print the middle one.
    if(len % 2 == 0){
        int mid = len / 2;
        float median = (n[mid - 1] + n[mid]) / 2.0;
        printf("Median: %.2f\n", median);
    } else {
        int mid = len / 2;
        printf("Median: %d\n", n[mid]);
    }
}

void stddev(){
    // Read the array length and its floating-point elements.
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    float n[len];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < len; i++){
        scanf("%f", &n[i]);
    }
    // Calculate the mean, then the population standard deviation.
    float mean, sum = 0.0,variance = 0.0, stddev = 0.0;
    for(int i = 0; i < len; i++){
        sum += n[i];
    }
    mean = sum / len;
    for(int i = 0; i < len; i++){
        variance += (n[i] - mean) * (n[i] - mean);
    }
    stddev = sqrt(variance / len);
    printf("Standard Deviation: %.2f\n", stddev);
}

void determinant(){
    // Keep asking until the matrix size is between 1 and 3.
    int n;
    do{
        printf("Enter the size of the Square matrix: ");
        scanf("%d", &n);
        if(n <= 0 || n > 3){
            printf("Size must be a positive integer between 1 and 3. Please try again.\n");
        } else {
            break;
        }
    } while(true);
    float matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    // Read every entry of the square matrix.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Matrix[%d][%d] = ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
    float det = 1;
    // Apply the determinant formula for the selected matrix size.
    switch(n){
        case 1:
            det = matrix[0][0];
            break;
        case 2:
            det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            break;
        case 3:
            det = (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) -
                  (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) +
                  (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));
            break;
        default:
            printf("Determinant calculation is only supported for matrices of size 1 to 3.\n");
            return;
    }
    printf("Determinant: %.2f\n", det);
}