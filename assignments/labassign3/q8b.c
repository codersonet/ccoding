/* (a) WAP to read three integer variables from keyboard using one scanf() statement
and O/P them in one line using: (i) three printf() statements (ii) one printf() with
conversion specifiers, and (iii) one printf() without conversion specifiers.

(b) WAP to print number numexp = 102.45678 in exponential format and
fixpt = 345.6789 in fixed -point decimal format as follows:
(i) two decimal points (ii) five decimal points (iii) zero decimal points 
Program make use of formatted output statement (printf()) [EBG/8th ed/pg.113-116] */

#include<stdio.h>                   // including libraries
int main(){
	double numexp = 102.45678;		// intialised value to numexp
	float fixpt = 345.6789;			// intialised value to fixpt
	printf("number in expo is %e\n", numexp);	// printing in exponential format
	printf("two decimal pts: %.2f\n", fixpt);	// printing upto two decimal
	printf("five decimal pts: %.5f\n", fixpt);	// printing upto five decimal
	printf("zero decimal pts: %.0f\n", fixpt);	// printing integer
	return 0;				// return zero after seccessful execution
}
