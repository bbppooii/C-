#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cctype>  // 用于 isspace()

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int a = s.size();
        int left = 0;

        // 遍历字符串
        for (int b = 0; b < a; b++) {
            if (isspace(s[b])) {
                // 当遇到空格时，反转从left到b-1的单词
                for (int right = b - 1; left < right; left++, right--) {
                    swap(s[left], s[right]);
                }
                left = b + 1;  // 继续查找下一个单词
            }
        }

        // 处理最后一个单词（没有空格的情况）
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
