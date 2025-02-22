#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    string reverseStr(string s, int k) {
        int a = s.size();
        for (int i = 0; i < a; i += 2 * k) {
            int left = i;
            int right = min(i + k - 1, a - 1);
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};