#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // 如果有一个是 0，直接返回 0

        int m = num1.size();
        int n = num2.size();
        string result(m + n, '0'); // 初始化结果字符串，全部填充为 '0'

        // 从右往左逐位相乘
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0'); // 当前位的乘积
                int sum = product + (result[i + j + 1] - '0'); // 加上之前的结果
                result[i + j + 1] = ('0' + (sum % 10)); // 更新当前位
                result[i + j] += sum / 10; // 更新进位
            }
        }

        // 去掉前导零
        size_t startPos = result.find_first_not_of('0');
        return startPos == string::npos ? "0" : result.substr(startPos);
    }
};

int main() {
    Solution solution;
    string num1, num2;

    // 测试用例 1
    num1 = "123";
    num2 = "456";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // 输出: 56088

    // 测试用例 2
    num1 = "0";
    num2 = "123";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // 输出: 0

    // 测试用例 3
    num1 = "999";
    num2 = "999";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // 输出: 998001

    return 0;
}