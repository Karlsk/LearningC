/*for_char.c ASSIC 循环显示*/
#include<stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    for ( ch = 'A';ch <= 'Z'; ch++)
    {
        printf("The ASCII value for %c is %d.\n", ch, ch);
    }
    for ( ch = 'a';ch <= 'z'; ch++)
    {
        printf("The ASCII value for %c is %d.\n", ch, ch);
    }
    
    return 0;
}
