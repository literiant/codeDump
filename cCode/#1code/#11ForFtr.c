#include <stdio.h>
// 用for循环实现阶乘
int main()
{
    int num, result = 1;
    printf("Enter a integer: ");
    scanf("%d", &num);
    if (num == 0)
        result = 1; // 定义0的阶乘为1，符合数学定义。否则下面的*=操作无法有效处理0的阶乘
    else
        for (int i = 1; i <= num; i++)
            result *= i;
    printf("Factorial of %d = %d\n", num, result);
    return 0;
}