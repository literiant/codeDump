#include <stdio.h>
int main()
{
    int i, j;
    int n, m;
    int arrn[100], arrm[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arrn[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &arrm[i]);

    for (i = 0; i < m; i++)
    {
        arrn[n + i] = arrm[i];
    }

    for (i = 0; i < n + m; i++)
    {
        for (j = 0; j < n + m - i - 1; j++)
        {
            if (arrn[j] > arrn[j + 1])
            {
                int temp = arrn[j];
                arrn[j] = arrn[j + 1];
                arrn[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n + m; i++)
    {
        printf("%d ", arrn[i]);
    }
    return 0;
}