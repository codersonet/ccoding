/* program to display the understanding the us of increment and decrement*/

#include <stdio.h>
int main(){
	int a=8, b=6, c, d, p, q, zd, zs, x=5, y;	// intializing variables
	printf("initially- a=%d | b=%d\n", a, b);
	c = ++a-b;		// ++a (pre-multiplier) first added 1 in a (a=9). Now, a-b = 9-6 = 3.
	printf("a=%d | b=%d\n",a,b);
	d = --a -b;		// --a will first change value of a=8 and then -b = 2
	printf("a=%d | b=%d\n",a,b);
	p = a++ +b;		// a++ (post-multiplier) first a=8+b=6 + 14, then a=9 (current value)
	printf("a=%d | b=%d\n", a,b);	
	q = a-- +b;		// a-- will first add to b which will give 15, then a-- will lead to a=8( (currrent value)
	printf("a=%d | b=%d\n",a,b);
	zd = a++ +a++;		// a will first added itself 	8 then a++ will make a=9 then it will add in previous a=8 leading to17 then again a++ will make a=10(current value)
	printf("a=%d | b=%d\n",a,b);
	zs = a++ +a;		// first a will take it's value 10, then a++ will increment it to 11, then 10+11 = 21
	printf("finally - a=%d | b=%d\n\n", a,b);
	
	y =  x++ + ++x + x++; 
	printf("x=%d | y=%d\n", x,y);
	/*
	for x: first x=5, x->6, then ++x -> x=7, then x++ -> x=8
	for y: first x=5, then x= 7, then again x=7 hence (5+7+7=19)
	*/
	return 0;	
}
