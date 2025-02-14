#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; --right, ++left) {
            swap(s[left], s[right]);
        }
    }
};