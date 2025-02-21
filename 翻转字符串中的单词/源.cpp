#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cctype>  // ���� isspace()

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int a = s.size();
        int left = 0;

        // �����ַ���
        for (int b = 0; b < a; b++) {
            if (isspace(s[b])) {
                // �������ո�ʱ����ת��left��b-1�ĵ���
                for (int right = b - 1; left < right; left++, right--) {
                    swap(s[left], s[right]);
                }
                left = b + 1;  // ����������һ������
            }
        }

        // �������һ�����ʣ�û�пո�������
        for (int right = a - 1; left < right; left++, right--) {
            swap(s[left], s[right]);
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s) << endl;  // Output: "s'teL ekat edoCteeL tsetnoc"
    return 0;
}
