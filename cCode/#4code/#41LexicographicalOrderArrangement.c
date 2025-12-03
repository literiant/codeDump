#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
int main()
{
    char a[N], *p[N] = {NULL};
    int q[N];
    int n = 0;
    while (fgets(a, sizeof(a), stdin))
    {
        a[strcspn(a, "\n")] = '\0';
        p[n] = malloc(strlen(a) + 1);
        strcpy(p[n], a);
        q[n] = n;
        n++;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (strcmp(p[q[j]], p[q[j + 1]]) > 0)
            {
                int w = q[j];
                q[j] = q[j + 1];
                q[j + 1] = w;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", p[q[i]]);
        free(p[q[i]]);
    }
    return 0;
}
