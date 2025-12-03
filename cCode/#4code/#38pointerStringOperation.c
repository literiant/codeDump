#include <stdio.h>
#include <stdlib.h>
// 计算长度
int myStrlen(char *str)
{
    int len = 0;
    char *p = str;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}
// 复制字符
char *myStrcpy(char *dest, char *src) // cpy(B,A).B为目的在先,A为手段在后.
{
    char *p_src = src;
    char *p_dest = dest;   // src和dest都储存着重要的首地址信息,不能改变,直接用原指针自加存在隐患，故临时指针很重要。
    while (*p_src != '\0') // 后续都要保证用的是临时指针
    {
        *p_dest = *p_src;
        p_src++;
        p_dest++;
    }
    *p_dest = '\0'; // 字符串合法格式
    return dest;
}
// 拼接字符
char *myStrcat(char *str1, char *str2)
{
    int len1 = myStrlen(str1);
    int len2 = myStrlen(str2);
    char *result = (char *)malloc(sizeof(char) * (len1 + len2 + 1)); // strlen不计'\0',这里要留一个内存给拼接字符的'\0'.
    if (result == NULL)
        exit(-1);
    char *p = result;
    char *p1 = str1;
    char *p2 = str2;
    while (*p1 != '\0')
    {
        *p = *p1;
        p++;
        p1++;
    }

    while (*p2 != '\0')
    {
        *p = *p2;
        p++;
        p2++;
    }
    *p = '\0';
    return result;
}
int main()
{
    char *str1 = (char *)malloc(sizeof(char) * 100);
    char *str2 = (char *)malloc(sizeof(char) * 100);

    if (str1 == NULL || str2 == NULL)
        return -1;

    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = myStrlen(str1);
    int len2 = myStrlen(str2);

    printf("Length of first string: %d\n", len1);
    printf("Length of second string: %d\n", len2);

    char *cpystr = (char *)malloc(sizeof(char) * (len1 + 1));
    myStrcpy(cpystr, str1);
    printf("Copied string: %s\n", cpystr);

    char *catstr = myStrcat(str1, str2);
    printf("Concatenated string: %s\n", catstr);

    free(str1);
    free(str2);
    free(cpystr);
    free(catstr);

    return 0;
}