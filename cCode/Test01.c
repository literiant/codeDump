#include <stdio.h>
int main()
{
    int a;
    float b;
    char c;
    printf("请输入一个整数，一个小数，一个字符：");
    scanf("%d %f", &a, &b);
    printf("a=%d b=%f,", a, b);
    getchar();
    scanf("%c", &c);
    printf("c=%c\n", c);
    return 0;
}