#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。

int main() 
{
    int year;
    int month;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (scanf("%d %d", &year, &month) != EOF) 
    {
        int day = days[month - 1];
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (month == 2) 
            {
                day += 1;
            }
        }
        printf("%d\n", day);
    }

    return 0;
}