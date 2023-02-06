/* pizza.c -- 在比萨饼程序中使用已定义的常量 */

#include<stdio.h>
#include<limits.h>

#define  PI 3.14159

int main(void)
{
    float area, circum, radius;
    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0 * PI *radius;

    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum,area);\

    printf("Maximum int value on this system = %d,%zd\n", INT_MAX,sizeof(int));
    printf("Maximum uint value on this system = %ul,%zd\n", UINT_MAX,sizeof(unsigned int));
    return 0;
}