#include <stdio.h>

int main()
{
    FILE *input, *output;
    input = fopen("input.c", "r");
    output = fopen("output.c", "w");
    if (input == NULL || output == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    //

    fclose(input);
    fclose(output);
    return 0;
}