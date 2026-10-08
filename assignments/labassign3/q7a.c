#include<stdio.h>		// importin libraries

int main(){			// using main()
	int a,b,c,x,y,z;	// initialising variables
	int p,q,r;
	printf("Enter three integer numbers: ");		// ask user to enter number
	scanf("%d %d %d", &a, &b, &c);				// assign the value to variables
	printf("%d %d %d \n\n", a,b,c);				// print the output using suitable format specifiers
	printf("Enter two 4-digit integer numbers: ");
	scanf("%2d %4d", &x, &y);
	printf("%d %d\n\n", x,y);
	printf("Enter two integers: ");
	scanf("%d %d", &a, &x);
	printf("%d %d\n\n", a,x);
	printf("Enter a nine digit number: ");
	scanf("%3d %4d %3d", &p,&q,&r);
	printf("%d %d %d\n\n",p,q,r);
	printf("Enter two three digit numbers: ");
	scanf("%d %d", &x, &y);
	printf("%d %d\n\n", x,y);
	return 0;		// return zero after successful execution
}
