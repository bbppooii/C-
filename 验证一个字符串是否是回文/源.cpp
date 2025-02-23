#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cctype> // ���� isalnum �� tolower
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            // ��������ĸ�����ַ�
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // �Ƚ��ַ������Դ�Сд��
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string input;

    // �������� 1
    input = "A man, a plan, a canal: Panama";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // ���: true

    // �������� 2
    input = "race a car";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // ���: false

    // �������� 3
    input = " ";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // ���: true

    // �������� 4
    input = "No 'x' in Nixon";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // ���: true

    return 0;
}