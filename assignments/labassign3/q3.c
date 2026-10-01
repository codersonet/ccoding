#include<stdio.h>

int main(){
	int x = 10; float y = 4.25; x = y%x; // error: float is modulo divison by int...... correction: we must have same type of data type to use modulo divison
	printf("Value of x is %d\n", x);
}
// % operator is used to specify the format and also used in modulo divison when we have same data types
