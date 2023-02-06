// hour_min.c -- 把分钟转换成小时和分钟
#include <stdio.h>

#define MIN_PER_HOUR 60 // 1小时60分钟

int main(int argc, char const *argv[])
{
    int mins, hours, left;

    printf("Convert min to hours and mins!\n");
    printf("Enter the number of mins (<=0 to quit):\n");
    scanf("%d",&mins);       // 读分钟

    while (mins > 0)
    {
        hours = mins / MIN_PER_HOUR;
        left = mins % MIN_PER_HOUR;
        printf("%d mins is %d hours, %d mins.\n", mins,hours, left);

        printf("Enter the number of mins (<=0 to quit):\n");
        scanf("%d",&mins);       // 读分钟
    }
    printf("Done!!");
    

    return 0;
}

