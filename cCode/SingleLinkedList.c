#include<stdio.h>
//第一步:定义结构体
struct node
{
    int data;//数据域
    struct node* next;//指针域
};
//第二步:创建单链表;遍历输入数据;遍历打印链表;
int createLink(int data[],int n)
{
                                        //建立头指针指向头结点.
    struct node* header;
    header = (struct node*)malloc(sizeof(struct node));
    header->next = NULL;                //头节点的data此处不用，为垃圾值.   但有时候可以用作链表长度记录.
                                        //尾指针:方便从尾部插入节点;不用重复遍历来寻找指向NULL的尾指针进行修改.
    struct node* q = header;
//遍历过程中新建节点.
    for(int i=0; i<n; i++)
    {
        struct node* s = (struct node*)malloc(sizeof(struct node));//添加section
        s->data = data[i];
        s->next = NULL;//新接在尾部的节点要自动指向NULL
        
        q->next = s;//q->next,即 header->next 由指向 NULL 转为指向 s 
        q = q->next;    //尾指针重新移动到链表尾部 此处为新接上的 s
    }

    struct node* p_display = header;
    while(p_display->next)  //指向NULL为假;能指向一个存在的next为真.
    {
        p_display = p_display->next; //临时指针遍历而不修改原链表.
        printf("%d",p_display->data);
    }
    printf("\n");
                      //64位中指针和整数的位数不同
    return(int)header;//此处做法有风险    //看后续要不要用到该链表来决定要不要返回值
};                                      //法一:直接返回链表头指针 return header
int main()                              //法二:无返回值(类型void 不用return)在函数参数值处通过二级指针来确定链表赋向.
{                                       //此时函数为void createLink (int data[],int n,struct node** result).
    int data[] = {1,2,3,4,5};           //result为二级指针 将函数结构尾处的*result = header 即头指针赋给第三个参数(一个地址)指向的指针.
    int n = 5;
    createLink(data,n);
    return 0;
}