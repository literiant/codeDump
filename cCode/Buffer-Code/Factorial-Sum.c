#include <stdio.h>
#include <string.h>
int factorial(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
        fac *= i;
    return fac;
}
// 阶乘和数-判定
int main()
{
    int num, fac;
    scanf("%d", &num);
    printf("%d,", num);
    char str[20];
    sprintf(str, "%d", num);
    int len = strlen(str);
    int Num[20];
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        Num[i] = str[i] - '0';
        Num[i] = factorial(Num[i]);
        sum += Num[i];
    }
    printf("%d", Num[len - 1]);
    for (int i = 1; i <= len - 1; i++)
        printf("+%d", Num[len - 1 - i]);
    printf("=%d\n", sum);
    if (num == sum)
        printf("Yes");
    else
        printf("No");
    return 0;
}