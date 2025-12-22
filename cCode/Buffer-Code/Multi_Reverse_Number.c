#include <stdio.h>
#include <string.h>
int reverse(int num)
{
    int reversed = 0;
    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}
int main()
{
    int number;
    scanf("%d", &number);
    int reversed = reverse(number);
    char Num[100], revNum[100];
    sprintf(Num, "%d", number);
    int len = strlen(Num);
    for (int i = 0; i < len; i++)
        revNum[i] = Num[len - 1 - i];
    revNum[len] = '\0';
    float k = (float)reversed / (float)number;
    if (k == (int)k)
        printf("%d*%d=%d", number, (int)k, reversed);
    else
    {
        printf("%d ", number);
        printf("%s", revNum);
    }
    return 0;
}