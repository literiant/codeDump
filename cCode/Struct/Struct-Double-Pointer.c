#include <stdio.h>
typedef struct student
{
    int id;
    char name[21];
    char gender;
} student;
int main()
{
    student stu[2] = {1, "stu1", 'm', 2, "stu2", 'f'};
    student *stuptr[2] = {stu, stu + 1};
    student **stu2ptr[2] = {stuptr, stuptr + 1};

    printf("%d %s %c\n", stu[0].id, stu[0].name, stu[0].gender);

    scanf("%d %s %c", &stu[0].id, stu->name, &stu[0].gender); // stu[0].id不可以，此处需要地址.
    // stu[0].id为int;&stu[0].id与stu->id等效

    scanf("%d %s %c", &stu[1].id, (stu + 1)->name, &stu[0].gender); // stu+1->name不行,优先级'->'大于'+'.

    printf("%d %s %c\n", (*stuptr)[0].id, (*stuptr)->name, (*stuptr)->gender); //'->'仅适用于指针;'.'仅适用于结构体变量;

    printf("%d %s %c", (**stu2ptr + 1)->id, (**stu2ptr)[1].name, (**stu2ptr + 1)->gender); // 指针不能自加
    return 0;
}
