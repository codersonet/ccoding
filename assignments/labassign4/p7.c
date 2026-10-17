#include <stdio.h>
#define rlen 3                  // define row length as 3
#define clen 3                  // define column length as 3
 
int main(){
        // declare 2D array nits and iitd
        int nits[rlen][clen], iitd[rlen][clen] = {{1,2,3},
                                                  {4,5,6},
                                                  {7,8,9}};

        // for iitd print element in one line
        printf("Elements of iitd array in one line:\n");
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("%d ", iitd[i][j]);
            }
        }
        printf("\n\n");

        // print int matrix form for iitd array
        printf("Matrix format:\n");     
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("%d ", iitd[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // print with each element location and value for iitd array
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("nits[%d][%d] = %d\n", i+1, j+1,iitd[i][j]);
            }
        }
        printf("\n\n");

        printf("x-x-x-x-x-x-x-x-x-x");

        printf("\n\n");
        // values for nits during run time
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("Enter nits[%d][%d]: ", i+1, j+1);
                    scanf("%d", &nits[i][j]);
                    }
        }
        printf("\n");

        // print only elements in a single line
        printf("Elements of nits array in one line:\n");
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("%d ", nits[i][j]);
            }
        }
        printf("\n\n");

        // print int matrix form
        printf("Matrix format:\n");     
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("%d ", nits[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // print with each element location and value
        for(int i = 0; i<rlen; i++){
            for(int j = 0; j<clen; j++){
                    printf("nits[%d][%d] = %d\n", i+1, j+1,nits[i][j]);

            }
        }
        return 0;
}       