#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDay(int year, int month)
{
    assert(month > 0 && month < 13);

    static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 判断是否为闰年，并处理 2 月份的天数
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    else
    {
        return monthDayArray[month];
    }
}

int main() {
    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    for (int i = 1; i < b; i++) {
        sum += GetMonthDay(a, i);
    }
    cout << sum + c;
}
