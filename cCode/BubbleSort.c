#include <stdio.h>
int main()
{
    int n = 0;
    int i, j;
    scanf("%d", &n);
    getchar();
    int arr[100] = {0};
    int tem = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        getchar();
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}