#include <stdio.h>
#include <stdlib.h>
// 单链表标准化创建。

// 1.定义节点结构体
struct node
{
    int data;
    struct node *next;
};
// 2.创建单链表函数
int createChainTable(int data[], int n)
{ // 初始化头尾节点.
    struct node *header;
    header = (struct node *)malloc(sizeof(struct node));
    header->next = NULL;

    struct node *q = header;

    for (int i = 0; i < n; i++)
    {
        struct node *s = (struct node *)malloc(sizeof(struct node));
        s->data = data[i];
        s->next = NULL;

        q->next = s; // 第一次的q就是start节点，start节点的next指向第一个新创建的节点s。
        q = s;
    }
    // 3.遍历单链表函数进行展示
    struct node *p_display = header;
    while (p_display->next)
    {
        p_display = p_display->next;
        printf("%d ", p_display->data);
    }
}
int main()
{
    int data[100];
    int i = 0;
    do
    {
        scanf("%d", &data[i]);
    } while (data[i++] != -1); // 要先存储数据才能够判断条件是否成立，当输入了最高有效值时，接下来的i+1位置是-1,但最后做判断时，又多进行了一次i++.
    i -= 2;                               // 所以这里要减2，才能得到最高有效值的index。
    for (int j = 0; j < (i + 1) / 2; j++) // 数组反转，只需进行具有有效值的最高index+1的一半次交换。
    {
        int temp;
        temp = data[j];
        data[j] = data[i - j];
        data[i - j] = temp;
    }
    createChainTable(data, i + 1); // 此处i+1严格为数据个数.不能依数组的用法。
    return 0;
}