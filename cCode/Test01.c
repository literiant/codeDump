#include <stdio.h>
int main()
{
    int a;
    float b;
    char c;
    printf("请输入一个整数，一个小数，一个字符：");
    scanf("%d %f", &a, &b);
    printf("a=%d b=%f,", a, b);
    getchar();//法1取走一个任意符;
    scanf("%c", &c);//法2占位符前加空格顶掉\n;
    printf("c=%c\n", c);
    return 0;
}
