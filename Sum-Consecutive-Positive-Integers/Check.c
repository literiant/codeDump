#include <stdio.h>

int main()
{
    FILE *input, *output;
    input = fopen("scpi.in", "r");
    output = fopen("scpi.out", "w");
    if (input == NULL || output == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }
    int x;
    fscanf(input, "%d", &x);
    int i = 1;
    int is = 0;
    int time = 0;
    int n = i;
    do
    {

        int sum = 0;
        int j = i;
        time = 0;
        do
        {

            sum += j;
            time++;
            j++;
        } while (sum < x);
        if (sum == x)
        {
            is = 1;
            n = i;
            break;
        }
        else
            i++;
    } while (i != x);
    if (is == 1)
    {
        fprintf(output, "%d=%d", x, n);
        for (int k = 1; k < time; k++)
            fprintf(output, "+%d", (n + k));
    }
    else
        fprintf(output, "%d:NOANSWER", x);
    fclose(input);
    fclose(output);
    return 0;
}