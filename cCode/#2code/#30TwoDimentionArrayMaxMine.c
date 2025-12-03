#include <stdio.h>
#include <stdlib.h>
// 查找行中最大值.
int rowMax(int arr[], int list)
{
    int max = *arr;
    for (int i = 0; i < list; i++)
    {
        if (max < *(arr + i))
            max = *(arr + i);
    }
    return max;
}
// 检查是否为列中最大值.
int islistMax(int arr[][10], int rowmax, int n, int m)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        if (rowmax < arr[i][m])
            result = 0;
    }
    return result;
}
// 组合打印
void printMax(int arr[][10], int n, int m)
{
    printf("%d %d %d\n", arr[n][m], n + 1, m + 1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[10][10] = {0};
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", arr[i] + j);
    }
    int rowmax[10] = {0};
    for (i = 0; i < n; i++)
        rowmax[i] = rowMax(arr[i], m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (rowmax[i] == arr[i][j])
            {
                if (islistMax(arr, arr[i][j], n, j))
                    printMax(arr, i, j);
            }
        }
    }
    return 0;
}