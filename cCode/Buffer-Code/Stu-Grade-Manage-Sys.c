#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int id;
    char name[50];
    float chinese;
    float math;
    float english;
    float sum;
} student; // 注意此处的';'打在定义的后边，代表"定义"语句的结束,struct 结构名{}变量名;代表创建结构类型;

// 从标准输入读取学生信息，返回学生人数，stu指向动态分配的学生数组
// 返回值为总人数n;函数体内要包括读取各项数据并计算总分sum的代码.
int ReadStuInfoFromStdin(student **stu)
{ // stu为双重指针
    int n;
    scanf("%d", &n);
    *stu = (student *)malloc(n * sizeof(student));
    // **stu = (student)malloc(n * sizeof(student));不可行,malloc返回值为任意指针.
    if (stu == NULL)
        return -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %f %f %f", &((*stu + i)->id), (*stu + i)->name, &((*stu + i)->chinese), &((*stu + i)->math), &((*stu + i)->english));

        (*stu + i)->sum = (*stu + i)->chinese + (*stu + i)->math + (*stu + i)->english;
    }
    return n;
}

// 获取不及格学生信息，返回不及格学生人数，noPassStudent指向动态分配的不及格学生数组
//
int NoPass(student stu[], int n, student **noPassStudent, int *m)
{
    int count = 0;
    *noPassStudent = (student *)malloc(n * sizeof(student));
    if (*noPassStudent == NULL)
        return -1;

    for (int i = 0; i < n; i++)
    {
        float aver = (stu[i].chinese + stu[i].math + stu[i].english) / 3;
        if (aver < 60)
        {
            (*noPassStudent)[count] = stu[i];
            count++;
        }
    }
    *m = count;
    return 0;
}

// 获取及格学生信息，返回及格学生人数，PassStudent指向动态分配的及格学生数组
int Pass(student stu[], int n, student **PassStudent, int *m)
{
    int count = 0;
    *PassStudent = (student *)malloc(n * sizeof(student));
    if (*PassStudent == NULL)
        return -1;

    for (int i = 0; i < n; i++)
    {
        float aver = (stu[i].chinese + stu[i].math + stu[i].english) / 3;
        if (aver >= 60)
        {
            (*PassStudent)[count] = stu[i];
            count++;
        }
    }
    *m = count;
    return 0;
}
// 对学生按总分进行降序排序
int SortStudents(student stu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            student temp;
            if (stu[j].sum < stu[j + 1].sum)
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
            if (stu[j].sum == stu[j + 1].sum)
            {
                float aver1 = (stu[i].chinese + stu[i].math + stu[i].english) / 3;
                float aver2 = (stu[i + 1].chinese + stu[i + 1].math + stu[i + 1].english) / 3;
                if (aver1 < aver2)
                {
                    temp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}

// 根据学生ID查找学生信息，返回0表示成功，-1表示失败，rank返回学生排名，rstu返回学生信息
int SearchStudent(student stu[], int n, int id, int *rank, student *rstu)
{
    for (int i = 0; i < n; i++)
    {
        if (id == stu[i].id)
        {
            *rank = i + 1;
            *rstu = stu[i];
            return 0;
        }
    }
    return -1;
}

/* 打印学生信息 */
int PrintStudents(student stu[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %.1f %.1f %.1f 总分=%.1f\n",
               stu[i].id, stu[i].name,
               stu[i].chinese, stu[i].math, stu[i].english, stu[i].sum);
    }
    return 0;
}

int main()
{
    int n, rank, id, i, m;
    student *stu = NULL, *noPassStu = NULL, *passStu = NULL, rstu;
    n = ReadStuInfoFromStdin(&stu); //
    if (n == 0)
        printf("read error");
    else
        PrintStudents(stu, n); //

    printf("\n不及格学生--------\n");
    i = NoPass(stu, n, &noPassStu, &m); //
    if (i == -1)
        printf("no pass error");
    else
        PrintStudents(noPassStu, m); //

    printf("\n及格学生--------\n");
    i = Pass(stu, n, &noPassStu, &m); //
    if (i == -1)
        printf(" pass error");
    else
        PrintStudents(noPassStu, m); //

    printf("\n排序后学生信息--------\n");
    // i = NoPass(stu, n, &noPassStu, &m);
    i = SortStudents(stu, n); //
    if (i == -1)
        printf("sort error");
    else
        PrintStudents(stu, n); //

    printf("\n查找的学生信息--------\n");
    scanf("%d", &id);
    i = SearchStudent(stu, n, id, &rank, &rstu); //
    if (i == -1)
        printf("search error");
    else
    {
        printf("rank:%d\n", rank);
        PrintStudents(&rstu, 1);
    }
    if (stu)
    {
        free(stu);
        stu = NULL;
    }
    if (noPassStu)
    {
        free(noPassStu);
        noPassStu = NULL;
    }
    if (passStu)
    {
        free(passStu);
        passStu = NULL;
    }
    return 0;
}
