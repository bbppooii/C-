#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <climits> // 包含 INT_MAX 和 INT_MIN 的定义
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0, bndry = INT_MAX / 10;
        int i = 0, sign = 1, length = str.size();

        // 处理空字符串
        if (length == 0) {
            return 0;
        }

        // 跳过开头的空格
        while (i < length && str[i] == ' ') {
            i++;
        }
        if (i == length) {
            return 0; // 字符串全是空格
        }

        // 处理符号
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }

        // 遍历数字字符
        for (int j = i; j < length; j++) {
            if (str[j] < '0' || str[j] > '9') {
                break; // 非数字字符，结束解析
            }

            // 检查是否会溢出
            if (res > bndry || (res == bndry && str[j] > '7')) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // 更新 res
            res = res * 10 + (str[j] - '0');
        }

        return res * sign;
    }
};
int main() {
    Solution solution;
    string input = "   -42";
    int result = solution.myAtoi(input);
    cout << "Result: " << result << endl; // 输出: Result: -42
    return 0;
}