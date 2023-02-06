/* swap1.c -- 第1个版本的交换函数 */

#include <stdio.h>

void interchange(int *u, int *v); /* 声明函数 */
void finterchange(int u, int v); /* 声明函数 */


int main(int argc, char const *argv[])
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    
    finterchange(x,y);
    printf("Not Use point Now x = %d and y = %d.\n", x, y);

    interchange(&x, &y);
    printf("Use point Now x = %d and y = %d.\n", x, y);
    return 0;
}

void interchange(int *u, int *v) /* 定义函数 */
{
    int temp;
    temp = *u; 
    *u = *v; 
    *v = temp;
}

void finterchange(int u, int v)
{
    int temp;
    temp = u; 
    u = v; 
    v = temp;
}