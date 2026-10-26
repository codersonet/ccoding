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
        printf("\n");
        float myflt[myfltlen];          // defining the array of float type
        for(int i=0; i<myfltlen; i++){
                printf("Enter myflt[%d]: ", i);
                scanf("%f", &myflt[i]);
        }

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
                        if(i >= myintlen){          // checking if the index is greater than the length of the integer array
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
        return 0;
}   

 int main(){
        arr();                  // calling arr function
        return 0;
}