#include <stdio.h>
#include <stdlib.h>
int main(){
	int num;
	char choice;                            // initalize variables
	do{                                          // using do while exit control loop 
  		//using printf() and scanf() for i/o
		printf("Enter a number between 1-128: ");
		scanf("%d", &num);                          
		if(num>= 1 && num<=128){
			printf("ASCII value of %d is %c\n", num, num);
		}
		else{                                      // checking if the number entered is zero or not, then print the respective conclusion
	     		if(num==0){
				printf("Zero is neither positive nor negative");
				}
	     		else{
				printf("Entered number is not a valid argument, pl enter a number strictly between 1-128\n");
				}
		}
	printf("Do you want to continue (y/n)?");    //asking user if they want to continue or not
	scanf(" %c", &choice);
	}while(choice == 'Y' || choice == 'y');      //checkinh what user wants to perform next
	return 0;	                                   // return 0 after successful execution
}
