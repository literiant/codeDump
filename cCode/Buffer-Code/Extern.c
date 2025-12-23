#include <stdio.h>
void num()
{
    extern int x, y; // 声明全局变量，指向下方的int x,y;
    int a = 15, b = 10;
    x = a - b;
    y = a + b;
} // 故这里的修改都直接对x,y生效.
int x, y;
int main()
{
    int a = 7, b = 5;
    x = a + b;
    y = a - b;
    num();
    printf("%d,%d\n", x, y);
}
