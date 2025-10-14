#include <stdio.h>
int main()
{
    // 初始定义，i,j多次调用，为方便可以在前面先定义.此外，此处存在值的交换，但不能损失值，要用到临时容器.
    int arr[6];
    int i, j, tem = 0;

    printf("Please enter 6 integers:\n");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    };
    // 人称冒泡排序.
    for (i = 0; i < 5; i++)         // 排列6个数，按顺序只需要对5个位置做处理
    {                               // 接下来这个循环会把大的数往前推
        for (j = 0; j < 5 - i; j++) // 5-i指示从最右侧开始依次处理
        {
            if (arr[j + 1] < arr[j])
            {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    };
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    return 0;
}
