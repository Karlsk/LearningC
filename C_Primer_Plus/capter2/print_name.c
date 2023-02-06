#include <stdio.h>

void print_name(char first_name[128],char last_name[128]);

int main(int argc, char const *argv[])
{
    char first_name[128],last_name[128];
    printf("first_name:");
    scanf("%s",&first_name);
    printf("last_name:");
    scanf("%s",&last_name);
    print_name(first_name,last_name);
    return 0;
}

void print_name(char first_name[128],char last_name[128])
{
    printf("%s %s\n",first_name,last_name);
    printf("%s\n",first_name);
    printf("%s\n",last_name);
    printf("%s %s\n",first_name,last_name);
}