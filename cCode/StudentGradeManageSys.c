#include <stdio.h>
int main()
{
    struct Student
    {
        char name[21];
        int gender;
        int birthday;
        float height;
        int codeG;
        int cacuG;
    };
    int num = 0;
    int i;
    int codeSum = 0, cacuSum = 0;
    ;
    struct Student student[100];
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%s %d %d %f %d %d",
              student[i].name,
              &student[i].gender,
              &student[i].birthday,
              &student[i].height,
              &student[i].codeG,
              &student[i].cacuG);
        codeSum += student[i].codeG;
        cacuSum += student[i].cacuG;
    }
    int codeAve, codeMax = student[0].codeG, codeMin = student[0].codeG;
    int cacuAve, cacuMax = student[0].cacuG, cacuMin = student[0].cacuG;
    codeAve = codeSum / num;
    cacuAve = cacuSum / num;
    for (i = 0; i < num; i++)
    {
        if (codeMax < student[i].codeG)
            codeMax = student[i].codeG;
        if (codeMin > student[i].codeG)
            codeMin = student[i].codeG;
        if (cacuMax < student[i].cacuG)
            cacuMax = student[i].cacuG;
        if (cacuMin > student[i].cacuG)
            cacuMin = student[i].cacuG;
    }
    // Code part
    printf("C_average:%d\n", codeAve);
    printf("C_max:%d\n", codeMax);
    for (i = 0; i < num; i++)
    {
        if (student[i].codeG == codeMax)
            printf("%s %d %d %.2f %d %d\n",
                   student[i].name,
                   student[i].gender,
                   student[i].birthday,
                   student[i].height,
                   student[i].codeG,
                   student[i].cacuG);
    }
    printf("C_min:%d\n", codeMin);
    // Calculus part
    printf("Calculus_average:%d\n", cacuAve);
    printf("Calculus_max:%d\n", cacuMax);
    for (i = 0; i < num; i++)
    {
        if (student[i].cacuG == cacuMax)
            printf("%s %d %d %.2f %d %d\n",
                   student[i].name,
                   student[i].gender,
                   student[i].birthday,
                   student[i].height,
                   student[i].codeG,
                   student[i].cacuG);
    }
    printf("Calculus_min:%d\n", cacuMin);
    return 0;
}
/*编写学生管理系统，定义学生结构体struct Student，

其中学生的信息包括姓名（汉语拼音，最多20个字符，长度21的字符数组），性别（男/女，用1表示男，2表示女，整数）、生日（19850101（年月日），整数）、身高（以m为单位，实数），还需要处理C语言、微积分两门课的成绩（整数）。

【输入形式】

输入学生的人数和每个学生的信息。

【输出形式】

身高输出时保留两位小数，请按照例子中进行输出，请勿输出其他字符。

输出每门课程的总平均成绩、最高分和最低分，以及获得最高分的学生的信息。

需要注意的是某门课程最高分的学生可能不只一人。

【样例输入】


3
zhangsan 1 19910101 1.85 85 90
lisi 1 19920202 1.56 89 88
wangwu 2 19910303 1.6 89 90
【样例输出】



C_average:87
C_max:89
lisi 1 19920202 1.56 89 88
wangwu 2 19910303 1.60 89 90
C_min:85
Calculus_average:89
Calculus_max:90
zhangsan 1 19910101 1.85 85 90
wangwu 2 19910303 1.60 89 90
Calculus_min:88*/
// 测试数据:3 zhangsan 1 19910101 1.85 85 90 lisi 1 19920202 1.56 89 88 wangwu 2 19910303 1.6 89 90