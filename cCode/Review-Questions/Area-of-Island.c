#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rank;
    scanf("%d", &rank);
    int *matrix = (int *)malloc(rank * rank * sizeof(int));
    int i, j;
    for (i = 0; i < rank; i++)
    {
        for (j = 0; j < rank; j++)
            scanf("%d", matrix + i * rank + j);
    }
    int area = 0;
    for (i = 1; i < rank - 1; i++)
    {
        for (j = 1; j < rank - 1; j++)
        {
            if (*(matrix + i * rank + j) == 0)
            {
                int *ptr = matrix + i * rank + j;
                int istop = 0, isbottom = 0;
                int isleft = 0, isright = 0;
                int k;
                for (k = 1; k <= i; k++)
                {
                    if (*(ptr - k * rank) == 1)
                        istop = 1;
                }
                for (k = 1; k < rank - i; k++)
                {
                    if (*(ptr + k * rank) == 1)
                        isbottom = 1;
                }
                for (k = 0; k <= j; k++)
                {
                    if (*(ptr - k) == 1)
                        isleft = 1;
                }
                for (k = 1; k < rank - j; k++)
                {
                    if (*(ptr + k) == 1)
                        isright = 1;
                }
                if (istop == 1 && isbottom == 1 && isleft == 1 && isright == 1)
                    area++;
            }
        }
    }
    free(matrix); // 至关重要,不释放可能会使结果为零。
    printf("%d", area);
    return 0;
}