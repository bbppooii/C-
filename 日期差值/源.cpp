#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �ж��Ƿ�������
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ����ĳ���ĳ���ж�����
int getDaysInMonth(int year, int month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29; // �����2����29��
    }
    return daysInMonth[month - 1];
}

// ������ת��Ϊ�ӹ�Ԫ0000�꿪ʼ������
int dateToDays(int year, int month, int day) {
    int days = 0;

    // �ۼӴ�0000�굽year-1�������
    for (int i = 0; i < year; ++i) {
        days += isLeapYear(i) ? 366 : 365;
    }

    // �ۼӵ����1�µ�month-1�µ�����
    for (int i = 1; i < month; ++i) {
        days += getDaysInMonth(year, i);
    }

    // ���ϵ��µ�����
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
