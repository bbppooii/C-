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
            int x1 = end1 >= 0 ? num1[end1--] - '0' : 0;  // ���ַ�ת��Ϊ����
            int x2 = end2 >= 0 ? num2[end2--] - '0' : 0;  // ���ַ�ת��Ϊ����
            int x = x1 + x2 + next;
            next = x / 10;  // �����λ
            x = x % 10;     // ���㵱ǰλ��ֵ
            str += ('0' + x);  // ������ת��Ϊ�ַ�����ӵ������
        }
        if (next == 1) {
            str += '1';  // ������λ�н�λ����� '1'
        }
        reverse(str.begin(), str.end());  // ��ת�ַ����õ����ս��
        return str;
    }
};

int main() {
    Solution solution;
    string num1, num2;

    // �������� 1
    num1 = "123";
    num2 = "456";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // ���: 579

    // �������� 2
    num1 = "999";
    num2 = "1";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // ���: 1000

    // �������� 3
    num1 = "0";
    num2 = "0";
    cout << "Input: " << num1 << " + " << num2 << endl;
    cout << "Output: " << solution.addStrings(num1, num2) << endl;  // ���: 0

    return 0;
}