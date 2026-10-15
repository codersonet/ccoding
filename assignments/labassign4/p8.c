#include <stdio.h>

int trace(){
        int rlen, clen, sum = 0;
        int mat[rlen][clen];

        printf("Enter row and coloum length: ");
                scanf("%d %d", &rlen, &clen);

        if(rlen == clen)
                printf("It is a square matrix.\n");
        else
                printf("It is not a square matrix\n.");

        // assigning values to matrix

        for(int i=1; i<=rlen; i++){
            for(int j=1; j<=clen; j++){
                printf("Enter element mat[%d][%d] = ", i, j);
                scanf("%d", &mat[i][j]);        
            }
        }

        // finding diagonal and trace
        if(rlen == clen){
                for(int i=1; i<=rlen; i++){
                        for(int j=1; j<=clen; j++){
                                if(i==j){
                                        sum+= mat[i][j];
                                        printf("%d ", mat[i][j]);
                                }
                        }
                }
                printf("Trace/sum of matrix is: %d", sum);
        }
        else
                printf("Trace is not possible for non-square matrix.\n");
        return 0;       
}

int main(){
        trace();
        return 0;
}