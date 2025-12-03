#include <stdio.h>
int main()
{
    int num[3];
    int isAppear[10] = {0}; // 本题关键:用isAppear来记录数的状态,再用if来绑定状态对应的执行操作.
    int i;
    printf("Please enter 3 integers ranging from 0 to 9:");
    for (i = 0; i < 3; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (num[i] == j)
            {
                isAppear[j] = 1;
                break;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (isAppear[i] == 0)
            printf("%d", i);
    }
    return 0;
}