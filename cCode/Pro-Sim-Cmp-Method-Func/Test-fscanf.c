#include <stdio.h>
#include <string.h>
int main()
{
    char word[] = "H e l l o , W o r l d !";
    printf("%s\n", word); // H e l l o , W o r l d !

    strcpy(word, "H e l l o , w o r l d !");
    printf("%s\n", word); // H e l l o , w o r l d !

    FILE *input;
    input = fopen("hello-world.c", "r");
    if (input == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    fscanf(input, "%s", word);
    printf("%s\n", word); // H
    fclose(input);

    scanf("%s", word);    // 输入:H e l l o , W o r l d !
    printf("%s\n", word); // H
    return 0;
}