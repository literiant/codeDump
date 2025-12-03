#include <stdio.h>

int main()
{
    int n, m;
    // 读取行数n和列数m
    scanf("%d %d", &n, &m);
    int arr[10][10]; // 因n、m≤10，用静态数组存储即可

    // 读取二维数组元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // 遍历每个元素，判断是否为“最大点”
    for (int i = 0; i < n; i++)
    {
        // 步骤1：找第i行的最大值
        int row_max = arr[i][0];
        for (int j = 1; j < m; j++) // 以0为初始值，从1开始遍历 减少循环次数.
        {
            if (arr[i][j] > row_max)
            {
                row_max = arr[i][j];
            }
        }

        // 步骤2：对该行每个元素，找其所在列的最大值并判断
        for (int j = 0; j < m; j++)
        {
            int col_max = arr[0][j];
            for (int k = 1; k < n; k++)
            {
                if (arr[k][j] > col_max)
                {
                    col_max = arr[k][j];
                }
            }
            // 若元素是行最大值且是列最大值，则输出（行列从1开始计数）
            if (arr[i][j] == row_max && arr[i][j] == col_max)
            {
                printf("%d %d %d\n", arr[i][j], i + 1, j + 1);
            }
        }
    }

    return 0;
}