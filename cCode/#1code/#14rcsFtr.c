#include <stdio.h>
// 递归:函数自身调用自身，不断递进，直到达到递归出口后回归
int factorial(int n) //(一个递归函数) / 定义函数:返回类型➕函数名➕(形参列表)➕{函数体}
{
    if (n == 0)
    {
        return 1;
    } // 递归出口,也即递进的终点，回归的起点
    else
    {
        return n * factorial(n - 1); // 递进过程
    }
}
int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d = %d\n", num, factorial(num));
    return 0;
}