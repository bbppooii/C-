#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cctype> // 用于 isalnum 和 tolower
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            // 跳过非字母数字字符
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // 比较字符（忽略大小写）
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

    // 测试用例 1
    input = "A man, a plan, a canal: Panama";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // 输出: true

    // 测试用例 2
    input = "race a car";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // 输出: false

    // 测试用例 3
    input = " ";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // 输出: true

    // 测试用例 4
    input = "No 'x' in Nixon";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Is palindrome? " << (solution.isPalindrome(input) ? "true" : "false") << endl; // 输出: true

    return 0;
}