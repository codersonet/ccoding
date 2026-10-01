#include <stdio.h>
#include <math.h>            // importing liraries
#define pi 3.14 	     // defining a constant value to PI
int main(){     
	int i;
	float rad, sinv, cosv;           // initialising variables
	for(i=0; i<=180; i=i+15){
		rad = i*(pi/180);        // since sin and cos function use radians so we have to convert degrees to radians
		sinv = sin(rad);
		cosv = cos(rad);
		printf("| sin(%d) = %f | cos(%d) = %f |\n", i, sinv, i, cosv);        // printing the table for different values of sin and cos
	}
	return 0;                         // return 0 after successful execution
}
