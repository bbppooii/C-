#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // �����һ���� 0��ֱ�ӷ��� 0

        int m = num1.size();
        int n = num2.size();
        string result(m + n, '0'); // ��ʼ������ַ�����ȫ�����Ϊ '0'

        // ����������λ���
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0'); // ��ǰλ�ĳ˻�
                int sum = product + (result[i + j + 1] - '0'); // ����֮ǰ�Ľ��
                result[i + j + 1] = ('0' + (sum % 10)); // ���µ�ǰλ
                result[i + j] += sum / 10; // ���½�λ
            }
        }

        // ȥ��ǰ����
        size_t startPos = result.find_first_not_of('0');
        return startPos == string::npos ? "0" : result.substr(startPos);
    }
};

int main() {
    Solution solution;
    string num1, num2;

    // �������� 1
    num1 = "123";
    num2 = "456";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // ���: 56088

    // �������� 2
    num1 = "0";
    num2 = "123";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // ���: 0

    // �������� 3
    num1 = "999";
    num2 = "999";
    cout << "Input: " << num1 << " * " << num2 << endl;
    cout << "Output: " << solution.multiply(num1, num2) << endl; // ���: 998001

    return 0;
}