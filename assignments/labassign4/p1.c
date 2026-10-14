#include <stdio.h>
#include <string.h>
#define mynumlen 10
#define revlen 20

int arr(){
        int mynum[mynumlen+1];          // adding a room for null terminator
        for(int i=0; i<mynumlen; i++){
                printf("Enter mynum[%d] ", i);
                scanf("%d", &mynum[i]);
        }
        //mynum[mynumlen-1] = '\0';             // manually explicit cap the string with a numm terminator

        printf("mynum: ");
        for(int i =0; i < mynumlen; i++){
                printf("%d ", mynum[i]);
        }
        printf("\n");
        return 0;               // return zero after successful execution
}

int reverse(){
        int revme[revlen+1];            // adding a room for null terminator
        printf("\n");
        for(int i=0; i<revlen; i++){
                printf("Enter revme[%d] ", i);
                scanf("%d", &revme[i]);
        }
        //revme[revlen-1] = '\0';               // manually explicit cap the string with a numm terminator

        printf("revme: ");
        for(int i=0; i<revlen; i++){
                printf("%d ", revme[i]);
        }
        printf("\n");
        printf("reversed: ");
        for(int i= revlen-1; i>= 0; i--){
                printf("%d ", revme[i]);
        }
        printf("\n"); 
        return 0;
}

int main(){
        arr();                  // calling arr function
        reverse();              // calling reverse function
        return 0;
}