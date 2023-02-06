#include<stdio.h>

void inch_to_cm(float inch);

int main(int argc, char const *argv[])
{
    float inch;
    printf("Please Input 英寸:");
    scanf("%f",&inch);
    // float res;
    // res = inch * 2.54;
    // printf("%.2f 英寸 = %.2f 厘米\n",inch,res);
    inch_to_cm(inch);
    return 0;
}

void inch_to_cm(float inch)
{
    float res;
    res = inch * 2.54;
    printf("%.2f 英寸 = %.2f 厘米\n",inch,res);
}

