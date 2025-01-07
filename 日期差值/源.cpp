#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 判断是否是闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算某年的某月有多少天
int getDaysInMonth(int year, int month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29; // 闰年的2月有29天
    }
    return daysInMonth[month - 1];
}

// 将日期转换为从公元0000年开始的天数
int dateToDays(int year, int month, int day) {
    int days = 0;

    // 累加从0000年到year-1年的天数
    for (int i = 0; i < year; ++i) {
        days += isLeapYear(i) ? 366 : 365;
    }

    // 累加当年从1月到month-1月的天数
    for (int i = 1; i < month; ++i) {
        days += getDaysInMonth(year, i);
    }

    // 加上当月的天数
    days += day;

    return days;
}

int main() {
    char date1[9], date2[9];

    while (scanf("%s %s", date1, date2) != EOF) {
        int year1 = atoi(date1) / 10000;
        int month1 = (atoi(date1) % 10000) / 100;
        int day1 = atoi(date1) % 100;
        int year2 = atoi(date2) / 10000;
        int month2 = (atoi(date2) % 10000) / 100;
        int day2 = atoi(date2) % 100;
        int days1 = dateToDays(year1, month1, day1);
        int days2 = dateToDays(year2, month2, day2);
        int diff = abs(days1 - days2) + 1;
        printf("%d\n", diff);
    }

    return 0;
}
