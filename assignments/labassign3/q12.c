#include<stdio.h>

void fibonacci(int n){
        int count, first=0, sec=1, next;                        // initalizing varibale to print fiobonacci series
        printf("\nx-----Fibonacci Series-----x\n");     // put condition in while where to stop the loop
        while(count<n){
                printf("%d ", first);           
                next = first + sec;     // calculate next term by adding the previous two
                first = sec;            // updates value for next iteration
                sec = next;             
                count++;                // increase counter by 1 each time (post-multiplier)
        }
        count=0, first =0, sec=1, next=0;
        printf("\n");
}
 int main(){
        int num;
        char choice;
        do{
                printf("Enter a number to prints it's fibonacci series: ");
                scanf("%d", &num);
                fibonacci(num);
                printf("Do you want to run again? (y/n)");
                scanf(" %c", &choice);
        }while(choice == 'Y' || choice == 'y');
        printf("\n");
        return 0;
 }
 