#include <stdio.h>
int main()
{
    char sen[51] = {0};
    scanf("%s", &sen);
    int len = 0;

    for (int i = 0; i < 51; i++)
    {
        if (sen[i] != 0)
            len++;
    }
    for (int i = 0; i < (len / 2); i++)
    {
        if (sen[i] != sen[len - i - 1])
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}

/*问题描述】
回文是正读和倒读都一样的句子。读入一个最大长度不超过50个字符的句子，判断其是否是回文。
【输入形式】
输入一个最大长度不超过50个字符的句子
【输出形式】
Yes/No
【输入样例】

abcba
【输出样例】

Yes*/