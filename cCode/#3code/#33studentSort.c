#include <stdio.h>
#include <string.h>
int main()
{
    struct Student
    {
        int num;
        char name[50];
        int old;
    } student[50];
    struct Student temp;
    int n;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %d",
              &student[i].num, student[i].name, &student[i].old);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(student[j].name, student[j + 1].name) > 0)
            {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%3d %6s %3d\n\n",
               student[i].num,
               student[i].name,
               student[i].old);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (student[j].num < student[j + 1].num)
            {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%3d %6s %3d\n\n",
               student[i].num,
               student[i].name,
               student[i].old);
    }
    return 0;
}
