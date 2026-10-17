#include <stdio.h>
#include <string.h>

int trace(){
    int rlen, clen, sum = 0;

    printf("Enter row and column length: ");
    scanf("%d %d", &rlen, &clen);

    // Declare the matrix rlen and clen have values
    int mat[rlen][clen];

    if(rlen == clen)
        printf("It is a square matrix.\n");
    else
        printf("It is not a square matrix.\n");

    // Assigning values to matrix (using 0-based indexing)
    for(int i=0; i<rlen; i++){
        for(int j=0; j<clen; j++){
            printf("Enter element mat[%d][%d] = ", i+1, j+1);
            scanf(" %d", &mat[i][j]);
        }
    }

    // Finding diagonal elements and trace
    printf("Diagonal elements are: ");
    if(rlen == clen){
        for(int i=0; i<rlen; i++){
            for(int j=0; j<clen; j++){
                if(i==j){
                    sum+= mat[i][j];
                    printf("%d ", mat[i][j]);
                }
            }
        }
        printf("\n");
        printf("Trace/sum of matrix is: %d\n", sum);
    }
    else
        printf("Trace is not possible for non-square matrix.\n");
        
    return 0;
}

int main(){
    trace();
    return 0;
}