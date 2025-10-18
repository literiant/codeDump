#include <stdio.h>
int main()
{
    float array[100] = {0};
    printf("Please enter the number of data you want to input:\n");
    int n;
    scanf("%d", &n);
    getchar();
    printf("Please enter %d datas:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
    }
    float sum[100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum[i] += array[j];
        }
    };
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", sum[i]);
    }

    return 0;
}