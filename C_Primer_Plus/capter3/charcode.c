/* charcode.c-显示字符的代码编号 */
#include<stdio.h>
#include<stdint.h>

int main(int argc, char const *argv[])
{
    char ch;
    printf("Please enter a character: ");
    scanf("%c",&ch);
    printf("The code for %c is %d.\n", ch, ch);
    getchar();
    getchar();
    return 0;
}
