/* guess.c -- 一个拖沓且错误的猜数字程序 */
#include <stdio.h>
#include <ctype.h> // 为isspace()函数提供原型


int main(void)
{
    char ch;
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((ch = getchar()) != 'y') /* 获取响应，与 y 做对比 */
    {
        if (ch == 'n')
        {
            printf("Well, then, is it %d?\n", ++guess);
        }else
        {
            printf("Sorry, I understand only y or n.\n");
        }
        
        while (getchar() != '\n')
        {
            continue;
        }
        
        
        
        
    }
    printf("I knew I could do it!\n");


    return 0;
}

