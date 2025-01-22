#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size(), l = n - 1, ans = n + 5;
        for (int r = n - 1; r >= 0; r--) {
            while (sum > x && l >= 0) sum -= nums[l--];
            if (sum == x) ans = min(ans, n - r + l);
            sum += nums[r];
        }
        return ans > n ? -1 : ans;
    }
};