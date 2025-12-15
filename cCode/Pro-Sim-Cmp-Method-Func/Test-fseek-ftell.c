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
    fseek(input, 10, SEEK_SET);
    fseek(input, 6, SEEK_CUR);
    fseek(input, -7, SEEK_CUR);
    int position = ftell(input);
    printf("当前文件位置: %d\n", position);

    char word[21];
    fscanf(input, "%s", word);
    printf("读取的单词: %s\n", word);

    fclose(input);
    fclose(output);
    return 0;
}