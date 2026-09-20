#include<stdio.h>
#include<stdlib.h>
#include<math.h>

static int min(int a, int b){
    return a < b ? a : b;
}

void pattern1(){
    int i, j;
    for(i=0; i<=5; i++){
        for(j=0; j<=5; j++){
            printf("*");       
        }
        printf("\n");
    }   
}
void pattern2(){
    int i, j;
    for(i=0; i<=5; i++){
        for(j=0; j<=i; j++){
            printf("*");       
        }
        printf("\n");
    }
}
void pattern3(){
    int i, j;
    for(i=0; i<=5; i++){
        for(j=1; j<=i; j++){
            printf("%d", j);       
        }
        printf("\n");
    }
}
void pattern4(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            printf("%d",i);
        }
        printf("\n");
    }
}
void pattern5(){

    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            printf("%d",i+j);
        }
        printf("\n");
    }
}
void pattern6(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5-i+1;j++){
            printf("*");
        }
        printf("\n");
    }
}
void pattern7(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5-i+1;j++){
            printf("%d", j);
        }
        printf("\n");
    }
}
void pattern8(){
    int i,j;
    for(i=0;i<5;i++){
        // spcae
        for(j=0;j<5-i-1;j++){
            printf(" ");
        }
        // star
        for(j=0;j<2*i+1;j++){
            printf("*");
        }
        // space
        for(j=0;j<5-i-1;j++){
            printf(" ");
        }
        printf("\n");
    }
}
void pattern9(){
    int i,j;
    for(i=0;i<5;i++){
        // space
        for(j=0;j<i;j++){
            printf(" ");
        }
        // star
        for(j=0;j<2*5-(2*i+1);j++){
            printf("*");
        }
        // space
        for(j=0;j<i;j++){
            printf(" ");
        }
        printf("\n");
    }
}
void pattern10(){
    int start = 1,i,j;
    for(i=0;i<5;i++){
        if(i%2==0) start = 1;
        else start = 0;
        for(j=0;j<=i;j++){
            printf("%d", start);
            start = 1 - start;
        }
        printf("\n");
    }
}
void pattern11(){
    int i,j;
    int space = 2*(5-1);
    for(i=1;i<=5;i++){
        // numbers
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        // space
        for(j=1;j<=space;j++){
            printf(" ");
        }
        //numbers
        for(j=i;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
        space -= 2;
    }
}
void pattern12(){
    int i,j, num = 1;
    for(i=1; i<=5;i++){
        for(j=1;j<=i;j++){
            printf("%d ", num);
            num+=1;

        }
        printf("\n");
    }
}
void pattern13(){
    int i,j;
    for(i=1;i<=5;i++){
        for(char ch='A'; ch<= 'A'+i; ch++){
            printf("%c ", ch);
        }
        printf("\n");
    }
    printf(" ");
}
/// @brief 
void pattern14(){
    int i,j;
    for(i=0;i<5;i++){
        for(char ch='A'; ch<= 'A'+(5-i-1); ch++){
            printf("%c ", ch);
        }
        printf("\n");
    }
}
void pattern15(){
    int i, j;
    for(i=0;i<5;i++){
        char ch = 'A' + i;
        for(j=0; j<=i; j++){
            printf("%c", ch);
        }
        printf("\n");
    }
}
void pattern16(){
    int i,j;
    for(i=0;i<5;i++){
        //space
        for(j=0; j<5-i-1; j++){
            printf(" ");
        }      
        //letter
        char ch ='A';
        int breakpoint = (2*i+1) / 2;        
        for(j=1; j<=2*i+1; j++){
            printf("%c", ch);
            if(j <= breakpoint) ch++;
            else ch--;
        }

        //space
         for(j=0; j<5-i-1; j++){
            printf(" ");
        }  
        printf("\n");
    }

}
void pattern17(){
    int i,j,iniS=0;
    for(i=0;i<5;i++){
        //stars
        for(j=1;j<=5-i;j++){
            printf("*");
        }
        //space
        for(j=0;j<iniS;j++){
            printf(" ");
        }
        //stars
        for(j=1;j<=5-i;j++){
            printf("*");
        }
        iniS+=2;
        printf("\n");
    }
}
void pattern18(){
    int i,j,iniS=8;
    for(i=0;i<5;i++){
        //stars
        for(j=0;j<=i;j++){
            printf("*");
        }
        //space
        for(j=0;j<iniS;j++){
            printf(" ");
        }
        //stars
        for(j=0;j<=i;j++){
            printf("*");
        }
        iniS-=2;
        printf("\n");
    }
}
void pattern19(){
    int i,j, iniS=2*5-2;
    for(i=1;i<=2*5-1;i++){
        int stars = i;
        if(i>5) stars=2*5-i;
        // stars
        for(j=1; j<=stars;j++){
            printf("*");
        }
        //space
        for(j=1; j<=iniS;j++){
            printf(" ");
        }
        //stars
        for(j=1;j<=stars;j++){
            printf("*");
        }
        if(i<5) iniS -=2;
        else iniS +=2;
        printf("\n");
    }
}
void pattern20(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==0 || i==5-1 || j==0 || j==5-1) printf("*");
            else printf(" ");

        }
        printf("\n");
    }
}
void pattern21(){
    int i,j;
    for(i=0;i<2*4-1;i++){
        for(j=0;j<2*4-1;j++){
            int top=i, left = j, right=2*4-2-j, down=2*4-2-i;
            printf("%d", 4 - min(min(top, down), min(left, right)));
        }
        printf("\n");
    }
}

int main(){
    pattern1();
    pattern2();
    pattern6();
    pattern3();
    pattern4();
    pattern5();
    pattern7();
    pattern8();
    pattern9();
    pattern10();
    pattern11();
    pattern12();
    pattern13();
    pattern14();
    pattern15();
    pattern16();
    pattern17();
    pattern18();
    pattern19();
    pattern20();
    pattern21();
    return 0;
}