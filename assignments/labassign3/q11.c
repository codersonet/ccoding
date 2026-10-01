#include <stdio.h>

void usingWhile(){		// created a function to print 0,1,2.......,9 using while
	int i=0;
	printf("x-----using while-----x\n");
	while(i<10){		// put condition in while where to stop the loop
		printf("%d\n", i);
		i++;		// post multiplier to increase the value of i
	}
	printf("\n");
}

void dowhile(){			// created a function to print 0,1,2.......,9 using do-while
	int j=0;		
 	char choice;		// initialising choice variable to store the user input for re-executions
 	do{		
 		printf("x-----using do-while-----x\n");	// put condition in while where to stop the loop
 		while(j<10){
		printf("%d\n", j);
		j++;
		}
		printf("\n");
		j=0;
 	printf("Enter do you want to run again (y/n)?"); // asking user if they wants to run the do-while again or not
 	scanf(" %c", &choice);
 	}while(choice == 'y' || choice == 'Y');		// checking the condition to react on the input received from the user
 	printf("\n");
}

int main(){				// calling functions to execute
	usingWhile();
	dowhile();
	return 0;			// return to 0 on successfull execution
}
