/*for_geo.c 固定调薪程序*/
#include<stdio.h>

#define BONDED 0.1

int main(int argc, char const *argv[])
{
    double curr_monry;
    printf("Enter your current Money per Month: ");
    scanf("%lf",&curr_monry);
    
   for (int i = 1; curr_monry < 25000; i++)
   {
    printf("current money: %lf, years: %d\n",curr_monry,i);
    curr_monry = curr_monry * (1.0+BONDED);
   }
   
    
    
    return 0;
}
