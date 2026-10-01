#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int printPrime(){						// initializing a function isPrime()
	int num = 1, i =1;
	while(i<=100){
		if (num<=1){					// checking the condition if number is equal to or less than 1
		printf("%d is not a prime number\n", num);	// printing not a prime number
		continue;
		}
		bool isPrime() = true;
		if(num==2){					// checking for the only even prime number
			isPrime = true;
		
		}
		else-if(num%2 == 0){				// removing all even numbers 
			isPrime = false;
		}
		else{
			for(int i =3; i <= sqrt(num); i+=2){	// checking for odd positive numbers till the sqaure root of that number only
				if(num%i == 0){
					isPrime = false;
					break;
				}
			}
		}
		if(isPrime){
		printf("%d is a prime number\n", num);		// printing the prime number
		}else{
		printf("%d is not a prime number\n", num);	// printing not a prime number
		}
		i++;
		num++;
	}
}

int main(){
	printrime();
	return 0;						// return zero after the successful execution
}
