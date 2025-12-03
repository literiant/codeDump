#include <stdio.h>
int main()
{
    int i, j;
    int n, m;
    int arrn[100], arrm[100];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arrn[i]);

    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &arrm[i]);

    int isconmon[100] = {0};
    int isunique = 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arrn[i] == arrm[j] && isconmon[j] == 0)
            {
                isunique = 0;
                printf("%d ", arrn[i]);
                for (int k = 0; k < m - j; k++)
                {
                    if (arrm[j + k] == arrn[i])
                    {
                        isconmon[j + k] = 1;
                    }
                }
                break;
            }
        }
    }
    if (isunique)
    {
        printf("No Answer");
    }
    return 0;
    ;
}