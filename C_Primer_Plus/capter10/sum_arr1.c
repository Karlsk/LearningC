// sum_arr1.c -- 数组元素之和
// 如果编译器不支持 %zd，用 %u 或 %lu 替换它
#include <stdio.h>

#define SIZE 10

int sum(int ar[], int n);
int sum1(int *ar);

int main(int argc, char const *argv[])
{
    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;
    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",sizeof(marbles));

    
}

int sum(int ar[], int n)
{
    long answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = answer + ar[i];
    }
    printf("The size of ar is %zd bytes.\n", sizeof(ar));
    return answer;
    
}


