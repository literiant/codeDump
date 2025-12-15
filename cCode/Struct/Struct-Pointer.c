#include <stdio.h>
#include <stdlib.h>
// 定义结构体
struct student
{
    int num;
    char name[20];
    char sex;
};

int main()
{
    // 定义结构体数组
    struct student sarr[3] = {1001, "wr1", 'm', 1003, "wr2", 'm', 1005, "wr3", 'm'};
    struct student *p; // 定义结构体指针

    p = sarr; // 数组本身就是地址，不用取地址
    int num = 0;
    num = p->num++; // 优先级'->'大于'='大于'++'
    // 即 num = p->num; (p->num)++;
    printf("num=%d,p->num=%d\n", num, p->num);

    // p->num上一步已经加一
    num = p++->num; // num=p->num，p=p+1
    // 即num = p->num; p++; 此时p == &sarr[1]
    printf("num=%d,p->num=%d\n", num, p->num);

    return 0;
}
