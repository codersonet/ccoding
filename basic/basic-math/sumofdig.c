#include<stdio.h>

int main(){
        int num, rem, sum=0, temp;
        printf("Enter a number to perform digit operation: ");
        scanf("%d", &num);
        temp = num;
        while(temp>0){
            rem = temp%10;
            sum = sum + rem;
            temp=temp/10;
        }
        printf("sum of digits of %d is %d\n", num, sum);
        return 0;
}