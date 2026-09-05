#include <stdio.h>
int main(){
    int length, width;
    float area, perimeter;
    area = 0;
    perimeter = 0;
    printf("TO CALCULATE AREA AND PERIMETER OF RECTANGLE\n");
    printf("Enter length of rectangle: ");
    scanf("%d", &length);
    printf("Enter width of rectangle: ");
    scanf("%d", &width);
    area = length*width;
    perimeter = 2*(length + width);
    printf("Area of rectangle: %.2f\n", area);
    printf("Perimeter of rectangle: %.2f\n", perimeter);
    return 0;
}