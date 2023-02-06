/* loccheck.c -- 查看变量被储存在何处 */
#include <stdio.h>

void mikado(int);/* 函数原型*/

int main(int argc, char const *argv[])
{
     /* main()的局部变量 */
    int pooh = 2, bah = 5;

    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);

    mikado(pooh);

    return 0;
}

void mikado(int bah)
{
    int pooh = 10; /* mikado()的局部变量 */
    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
}