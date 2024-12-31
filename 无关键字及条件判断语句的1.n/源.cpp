#define _CRT_SECURE_NO_WARNINGS 1
class sum {
public:
    sum() {
        _ret += _i;
        ++_i;
    }
    static int GetRet() {
        return _ret;
    }
private:
    static int _i;
    static int _ret;
};
int sum::_i = 1;
int sum::_ret = 0;
class Solution {
public:
    int Sum_Solution(int n) {
        sum arr[n];
        return sum::GetRet();
    }
};