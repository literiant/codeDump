#include <stdio.h>
#include <string.h>
int main()
{
    char nation[100][100];
    char *p[100];
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%s", nation[i]);
        p[i] = nation[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(p[j], p[j + 1]) > 0)
            {
                char *temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", p[i]);
    }
    return 0;
}
