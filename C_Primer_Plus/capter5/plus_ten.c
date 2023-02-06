/*plus_ten 打印输入数字及后面十个数字*/
#include<stdio.h>

#define RNAGE 10

int main(int argc, char const *argv[])
{
    int num,cur;
    printf("Enter you num(>0): ");
    scanf("%d",&num);
    cur = num;
    while (num <= cur + RNAGE)
    {
        printf("%d\t",num);
        num++;
    }
    
    
    return 0;
}
