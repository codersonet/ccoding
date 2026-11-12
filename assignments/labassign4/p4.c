#include <stdio.h>
#define myintlen 5
#define myfltlen 10
#define revmelen 20

int arr(){
        int myint[myintlen];          // defining the array of integer type
        for(int i=0; i<myintlen; i++){
                printf("Enter myint[%d]: ", i);
                scanf("%d", &myint[i]);
        }

        // reversing the matrix myint
        printf("Reversed myint matrix: ");
        for(int i = myintlen - 1; i >= 0; i--){
                printf("%d ", myint[i]);
        }
        printf("\n");

        // defining the array of float types
        float myflt[myfltlen];          
        for(int i=0; i<myfltlen; i++){
                printf("Enter myflt[%d]: ", i);
                scanf("%f", &myflt[i]);
        }

        // reversing the matrix myflt
        printf("Reversed myflt matrix: ");
        for(int i = myfltlen - 1; i >= 0; i--){
                printf("%f ", myflt[i]);
        }
        printf("\n");

        int revme[revmelen];            // defining the array of integer type
        if(myintlen > myfltlen){
                for(int i=0; i<myintlen; i++){
                    if(i >= myfltlen){              // checking if the index is greater than the length of the float array
                                revme[i] = myint[i];         // assigning values to the array
                                printf("revme[%d]: %d\n", i, revme[i]);
                                continue;
                        }
                        else{
                                  revme[i] = myint[i] + myflt[i];         // assigning values to the array
                                printf("revme[%d]: %d\n", i, revme[i]);
                        }
                }
        }
        else{
                for(int i=0; i<myfltlen; i++){
                        if(i >= myintlen){          // checkiing if the index is greater than the length of the integer array
                                revme[i] = myflt[i];         // assigning values to the array
                                printf("revme[%d]: %d\n", i, revme[i]);
                                continue;
                        }
                        else{
                                  revme[i] = myint[i] + myflt[i];         // assigning values to the array
                                printf("revme[%d]: %d\n", i, revme[i]);
                        }
                }
        }
        printf("No of elements in revme is %d.\n", myfltlen + myintlen);

        //sum of all elements in array revme
        int sum = 0;
        for(int i = 0, n = myfltlen + myintlen; i < n; i++)
        {
                sum = sum + revme[i];
        }
        printf("Sum of all elements of revme is \'%d\'.\n", sum);
        return 0;
}   

 int main(){
        arr();                  // calling arr function
        return 0;
}