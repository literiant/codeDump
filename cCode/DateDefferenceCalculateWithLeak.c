#include <stdio.h>
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
int daysInYear(int year)
{
    if (isLeapYear(year))
        return 366;
    else
        return 365;
}
int daysInMonth(int year, int month)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else
        return 31;
}
int main()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date1, date2;
    scanf("%d %d %d", &date1.year, &date1.month, &date1.day);
    scanf("%d %d %d", &date2.year, &date2.month, &date2.day);
    int difference = 0;
    int i;
    for (i = 0; i < date2.year - date1.year; i++)
    {
        difference += daysInYear(date1.year + i);
    }

    if (date2.year == date1.year)
    {
        for (i = date1.month; i < date2.month; i++)
        {
            difference += daysInMonth(date1.year, i);
        }
        difference += date2.day - date1.day;
        if (date1.month == 1 && date2.month == 12 && date1.day == 1 && date2.day == 31)
            difference += 1;
    }
    else
    {
        if (date1.month < date2.month)
            for (i = date1.month; i < date2.month; i++)
            {
                difference += daysInMonth(date1.year, i);
            }
        else
        {
            int overDays = 0;
            for (i = date2.month; i < date1.month; i++)
            {
                overDays += daysInMonth(date2.year, i);
            }
            overDays += date1.day - date2.day;
            difference -= overDays;
        }
    }
    printf("%d\n", difference);
    return 0;
}
// 总会漏掉一个difference = 366的情况。原因不明。