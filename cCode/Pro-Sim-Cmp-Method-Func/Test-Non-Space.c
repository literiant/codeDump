#include <stdio.h>
#include <ctype.h>

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
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        if (!isspace(c))
            fputc(c, output);
    }
    fclose(input);
    fclose(output);
    return 0;
}