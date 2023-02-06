#include <stdio.h>
void print_agetoday(int age);

int main(int argc, char const *argv[])
{   
    int age;
    printf("输入你的年龄：");
    scanf("%d",&age);
    print_agetoday(age);
    return 0;
}

void print_agetoday(int age)
{
    int days;
    days = age * 365;
    printf("你的年龄是：%d,一共是%d天!\n",age,days);
}