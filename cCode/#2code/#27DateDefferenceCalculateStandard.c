#include <stdio.h>

// 定义日期结构
struct Date
{
    int year;
    int month;
    int day;
};

// 判断是否为闰年
int isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算从1900年1月1日到输入日期的累计天数
int calculateDays(struct Date d)
{
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    // 累加年份的天数（1900年到输入年份的前一年）
    for (int y = 1900; y < d.year; y++)
    {
        days += isLeap(y) ? 366 : 365;
    }

    // 累加月份的天数（1月到输入月份的前一月）
    for (int m = 1; m < d.month; m++)
    {
        if (m == 2 && isLeap(d.year))
        {
            days += 29; // 闰年二月有29天
        }
        else
        {
            days += monthDays[m];
        }
    }

    // 累加当月的天数（输入日的前一天，因为从1日开始计数）
    days += d.day - 1;

    return days;
}

int main()
{
    struct Date d1, d2;
    // 读取两个日期
    scanf("%d %d %d", &d1.year, &d1.month, &d1.day);
    scanf("%d %d %d", &d2.year, &d2.month, &d2.day);

    // 计算两个日期的累计天数并求差
    int days1 = calculateDays(d1);
    int days2 = calculateDays(d2);
    printf("%d\n", days2 - days1);

    return 0;
}