#include <stdio.h>
void salary(void){
    float bs, hra, da, gs, ded;
    scanf("%f", &bs);
    hra = 0.15 * bs; // HRA is 15% of basic salary
    da = 0.1 * bs;  // DA is 10% of basic salary
    ded = 0.05 * bs; // Deduction is 5% of basic salary
    gs = bs + hra + da - ded;
    printf("Gross Salary: %.2f\n", gs);
}
int main(void){
    printf("Enter basic salary: ");
    salary();
    return 0;
}