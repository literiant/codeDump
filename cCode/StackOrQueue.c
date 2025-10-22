#include <stdio.h>
int main()
{
    int T = 0;
    scanf("%d", &T);
    getchar();
    struct TestCase
    {
        int N;
        int in[100];
        int out[100];
    };
    struct TestCase cases[100];
    int i = 0, j = 0;
    for (i = 0; i < T; i++)
    {
        scanf("%d", &cases[i].N);
        getchar();
        for (j = 0; j < cases[i].N; j++)
            scanf(" %d", &cases[i].in[j]);
        for (j = 0; j < cases[i].N; j++)
            scanf(" %d", &cases[i].out[j]);
    }
    for (i = 0; i < T; i++)
    {
        int isStack = 1, isQueue = 1;
        for (j = 0; j < cases[i].N; j++)
        {
            if (cases[i].in[j] != cases[i].out[j])
                isQueue = 0;
            if (cases[i].in[j] != cases[i].out[cases[i].N - j - 1])
                isStack = 0;
        }
        if (isQueue == 0 && isStack == 0)
            printf("neither\n");
        if (isQueue == 1 && isStack == 1)
            printf("both\n");
        if (isQueue == 1 && isStack == 0)
            printf("queue\n");
        if (isQueue == 0 && isStack == 1)
            printf("stack\n");
    }
    return 0;
}