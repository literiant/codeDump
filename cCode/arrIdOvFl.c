#include <stdio.h>
int main()
{
    int num;
    char cs1[5] = {'n', 'n', 'n', 'n', 'n'};
    char cs2[5] = {'n', 'n', 'n', 'n', 'n'};
    printf("Please enter an integer:");
    scanf("%d", &num);
    cs2[num] = 'Y';
    for (int i = 0; i < 5; i++)
    {
        printf("cs1第%d个:%c\n", i, cs1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("cs2第%d个:%c\n", i, cs2[i]);
    }
    return 0;
}
/*这里研究数组的越界访问问题,超出部分进入了一种类似循环的东西(只循环单遍，再次遍历回到cs2[0]时后续无意义，赋值不再产生效果.)
  总而言之，数组越界访问后的结果仅局部可预测*/