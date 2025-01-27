#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void GetDay(int year, int day){
    int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month = 1;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        monthDayArray[2] = 29;
    }
        while (day > monthDayArray[month] && month < 12) {        
            day -= monthDayArray[month];
            month++;
        }
        printf("%04d-%02d-%02d\n", year, month, day);         
}
int main() {
    int a, b;
    while (cin >> a >> b) {
        GetDay(a, b);
    }
}