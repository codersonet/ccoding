#include<stdio.h>

void fibonacci(int n){		
 	char choice;		// initialising choice variable to store the user input for re-executions
 	do{		
 		int count, first=0, sec=1, next;			// initalizing varibale to print fiobonacci series
 		printf("\nx-----Fibonacci Series-----x\n");	// put condition in while where to stop the loop
 		while(count<n){
 			printf("%d ", first);
 			
 			next = first + sec;	// calculate next term by adding the previous two
 			first = sec;		// updates value for next iteration
 			sec = next;		
 			count++;		// increase counter by 1 each time (post-multiplier)
		
		}
		count=0, first =0, sec=1, next=0;
		printf("\n");
 	printf("Enter do you want to run again (y/n)?"); // asking user if they wants to run the do-while again or not
 	scanf(" %c", &choice);
 	}while(choice == 'y' || choice == 'Y');		// checking the condition to react on the input received from the user
 	printf("\n");
}
 int main(){
 	int num;
 	printf("Enter a number to prints it's fibonacci series: ");
 	scanf("%d", &num);
 	fibonacci(num);
 	return 0;
 }
