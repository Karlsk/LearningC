#include<stdio.h>

char get_choice(void);
void count(void);
char get_first(void);

int main(int argc, char const *argv[])
{
    char choice;

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a': printf("Buy low, sell high.\n");
            break;
        case 'b':  putchar('\a'); /* ANSI */
            break;
        case 'c': count();
            break;
        default: printf("Program error!\n");
            break;
        }
    }
    

    return 0;
}

char get_choice(void)
{
    char ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice                b. bell\n");
    printf("c. count                 q. quit\n");

    ch = getchar();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        // ch = getchar();
        ch = get_first();
    }

    return ch;   
}

char get_first(void)
{
    char ch;
    ch = getchar(); /* 读取下一个字符 */
    while (getchar() != '\n')
    {
       continue; /* 跳过该行剩下的内容 */
    }
    return ch;

}

void count(void)
{
    int n, i;
    printf("Count how far? Enter an integer:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
}