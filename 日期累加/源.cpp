#include <iostream>
using namespace std;
bool isleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else return false;
}
void addday(int year, int month, int day, int add) {
    int monthDayArray[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
                           {0,31,29,31,30,31,30,31,31,30,31,30,31} };
    add += day;
    int leap = isleapyear(year);
    while (add > monthDayArray[leap][month]) {
        add -= monthDayArray[leap][month];
        month++;
        if (month > 12) {
            month = 1;
            year++;
            leap = isleapyear(year);
        }
    }
    printf("%04d-%02d-%02d\n", year, month, add);
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        addday(a, b, c, d);
    }
    return 0;
}