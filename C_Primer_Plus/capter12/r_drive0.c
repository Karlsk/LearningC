//12.8 r_drive0.c驱动程序
/* r_drive0.c -- 测试 rand0()函数 */
#include<stdio.h>

extern unsigned int rand0(void);

int main(void)
{
    int count;
    for (count = 0; count < 5; count++)
    {
        printf("count=%d, rand=%d\n", count,rand0());
    }

    return 0;
}
