#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 先合并后排序

void str_bin(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int i = 0, j = 0;
    int added = 0;
    // 合并
    while (str2[i] != '\0')
    {
        // 检查是否重复
        int isHave = 0;
        for (j = 0; j < len1 + added; j++)
        {
            if (str2[i] == str1[j])
            {
                isHave = 1;
            }
        }
        // 不重复则添加
        if (isHave == 0)
        {
            str1[len1 + added] = str2[i];
            added++;
        }
        i++;
    }
    // 添加结束符
    str1[len1 + added] = '\0';

    // 排序
    for (i = 0; i < len1 + added - 1; i++)
    {
        for (j = 0; j < len1 + added - 1 - i; j++)
        {
            if (str1[j] > str1[j + 1])
            {
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char str1[201];
    char str2[101];
    scanf("%s", str1);
    scanf("%s", str2);

    str_bin(str1, str2);
    printf("%s\n", str1);
    return 0;
}