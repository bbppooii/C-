#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string str;
        int next = 0;
        while (end1 >= 0 || end2 >= 0) {
            int x1 = end1 >= 0 ? num1[end1--] - '0' : 0;  // 将字符转换为数字
            int x2 = end2 >= 0 ? num2[end2--] - '0' : 0;  // 将字符转换为数字
            int x = x1 + x2 + next;
            next = x / 10;  // 计算进位
            x = x % 10;     // 计算当前位的值
            str += ('0' + x);  // 将数字转换为字符并添加到结果中
        }
        if (next == 1) {
            str += '1';  // 如果最高位有进位，添加 '1'
        }
        reverse(str.begin(), str.end());  // 反转字符串得到最终结果
        return str;
    }
};

int main() {
    Solution solution;
    string num1, num2;

    // 测试用例 1
    num1 = "123";
    num2 = "456";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // 输出: 579

    // 测试用例 2
    num1 = "999";
    num2 = "1";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // 输出: 1000

    // 测试用例 3
    num1 = "0";
    num2 = "0";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // 输出: 0

    return 0;
}