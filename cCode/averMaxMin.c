#include <stdio.h>
int main()
{
    int num[10]; // 10个数，但序数是从0开始到9
    int sum = 0;
    int counter = 0;
    float aver;

    printf("Please enter 10 integers: ");
    // 第一个for:扫描填入10个值
    for (int i = 0; i < 10; i++)
    {
        if (scanf("%d", &num[i]) == 0) // scanf函数如果成功读取并转储数据，它的返回值便为1，否则为0;
        {
            printf("Error: Invalid input. Please enter 10 integers:\n");
            return 1;
        }
        sum += num[i];
    };
    // 通过初定义max和min,遍历各个值作比，有更符合的值则交换
    int max = num[0], min = num[0], maxId = 0, minId = 0; // 注意这里的赋值,要先通过scanf依次扫描给num赋好值，才能给max和min赋值
    // 第二个for:找max和min
    for (int i = 1; i < 10; i++)
    {
        if (max < num[i])
        {
            max = num[i];
            maxId = i + 1;
        }
        if (min > num[i])
        {
            min = num[i];
            minId = i + 1;
        }
    }
    aver = (float)sum / 10;
    // 第三个for:找大于平均数的个数(分出这个for的原因:先算出aver值才能比较计数)
    for (int i = 0; i < 10; i++)
    {
        if (num[i] > aver)
            counter++;
    }
    printf("The average value of the 10 integers is:%.1f\n", aver);
    printf("The maximum value of the 10 integers is:%d,its index is:%d\n", max, maxId);
    printf("The minimum value of the 10 integers is:%d,its index is:%d\n", min, minId);
    printf("The number of integers greater than the average value is:%d\n", counter);
    return 0;
}
