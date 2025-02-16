#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <climits> // ���� INT_MAX �� INT_MIN �Ķ���
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0, bndry = INT_MAX / 10;
        int i = 0, sign = 1, length = str.size();

        // ������ַ���
        if (length == 0) {
            return 0;
        }

        // ������ͷ�Ŀո�
        while (i < length && str[i] == ' ') {
            i++;
        }
        if (i == length) {
            return 0; // �ַ���ȫ�ǿո�
        }

        // �������
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }

        // ���������ַ�
        for (int j = i; j < length; j++) {
            if (str[j] < '0' || str[j] > '9') {
                break; // �������ַ�����������
            }

            // ����Ƿ�����
            if (res > bndry || (res == bndry && str[j] > '7')) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // ���� res
            res = res * 10 + (str[j] - '0');
        }

        return res * sign;
    }
};
int main() {
    Solution solution;
    string input = "   -42";
    int result = solution.myAtoi(input);
    cout << "Result: " << result << endl; // ���: Result: -42
    return 0;
}