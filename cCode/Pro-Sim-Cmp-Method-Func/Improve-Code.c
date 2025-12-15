#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNCS 10
#define MAX_LEN 21

int is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main()
{
    FILE *in = fopen("input.c", "r"), *out = fopen("output.c", "w");
    char funcs[MAX_FUNCS][MAX_LEN], word[MAX_LEN], c;
    int func_count = 0, in_main = 0, i, found;

    // 第一遍：收集自定义函数名
    fseek(in, 0, SEEK_SET);
    while (fscanf(in, "%20s", word) != EOF && strcmp(word, "main") != 0)
    {
        long pos = ftell(in);
        while ((c = fgetc(in)) != EOF && is_space(c))
            ;

        if (c == '(')
        {
            found = 0;
            for (i = 0; i < func_count; i++)
                if (strcmp(funcs[i], word) == 0)
                {
                    found = 1;
                    break;
                }

            if (!found && func_count < MAX_FUNCS)
                strcpy(funcs[func_count++], word);
        }

        fseek(in, pos, SEEK_SET);
    }

    // 第二遍：处理文件
    fseek(in, 0, SEEK_SET);
    in_main = 0;

    while ((c = fgetc(in)) != EOF)
    {
        if (is_space(c))
            continue;

        // 检查是否进入main函数
        if (c == 'm' && !in_main)
        {
            char buf[5];
            long pos = ftell(in) - 1;
            fseek(in, pos, SEEK_SET);

            if (fscanf(in, "%4s", buf) == 1 && strcmp(buf, "main") == 0)
                in_main = 1;

            fseek(in, pos, SEEK_SET);
            continue;
        }

        // 处理标识符
        if (isalpha(c) || c == '_')
        {
            char id[MAX_LEN];
            int idx = 0;
            id[idx++] = c;

            while ((c = fgetc(in)) != EOF && (isalnum(c) || c == '_') && idx < MAX_LEN - 1)
                id[idx++] = c;

            id[idx] = '\0';

            if (c != EOF)
                ungetc(c, in);

            // 检查是否是自定义函数名
            found = 0;
            for (i = 0; i < func_count; i++)
            {
                if (strcmp(funcs[i], id) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
                fputs(id, out);
        }
        else
        {
            fputc(c, out);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}