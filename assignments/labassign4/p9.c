#include <stdio.h>
#define rlen 5                  // define row length as 5
#define clen 5                  // define column length as 5

int main(){
    int matrix[rlen][clen];          // declare 2D array matrix
    for(int i = 0; i<rlen; i++){        // loop to take input for matrix elements
        for(int j = 0; j<clen; j++){
            if(i+j<clen-1)
                matrix[i][j] = 1;        // assign 1 to the upper-left triangle
            else if(i+j>clen-1)
                matrix[i][j] = -1;        // assign -1 to the lower-right triangle
            else
                matrix[i][j] = 0;        // assign 0 to elements on and above the diagonal                }
        }
    }
    for(int i = 0; i<rlen; i++){        // loop to print the matrix elements
        for(int j = 0; j<clen; j++){
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

