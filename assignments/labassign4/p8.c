#include <stdio.h>

int trace()
{
        int rlen, clen, sum = 0;

        printf("Enter row and coloum length: ");
                scanf("%d %d", &rlen, &clen);

        int mat[rlen][clen];

        if(rlen == clen)
                printf("It is a square matrix.\n");
        else
                printf("It is not a square matrix\n.");

        // assigning values to matrix

        for(int i=0; i<rlen; i++){
                for(int j=0; j<clen; j++){
                        printf("Enter element mat[%d][%d] = ", i+1, j+1);
                        scanf("%d", &mat[i][j]);        
                }
        }

        // finding diagonal and trace
        printf("Diagonal Elements: \n");
        if(rlen == clen){
                for(int i=0; i<rlen; i++){
                        for(int j=0; j<clen; j++){
                                if(i==j)
                                {
                                        sum+= mat[i][j];
                                        printf("%d ", mat[i][j]);
                                }
                                else
                                {
                                        printf(" ");
                                }
                        }
                        printf("\n");
                }
                printf("Trace/sum of matrix is: %d\n", sum);
        }
        return 0;       
}

int main(){
        trace();
        return 0;
}