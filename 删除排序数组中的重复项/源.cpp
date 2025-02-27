#include <iostream>
#include <vector>
using namespace std;

// 定义一个全局函数，而不是类成员函数
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0; // 如果数组为空，直接返回 0
    }

    size_t newLength = 1; // 新数组的长度，初始为 1（第一个元素肯定不重复）
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) { // 如果当前元素与前一个元素不同
            nums[newLength++] = nums[i]; // 将当前元素放到新数组的下一个位置
        }
    }

    return newLength; // 返回新数组的长度
}

// 测试函数
void testRemoveDuplicates() {
    // 测试用例 1
    vector<int> nums1 = { 1, 1, 2 };
    int len1 = removeDuplicates(nums1);
    cout << "Test Case 1: ";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl; // 预期输出: 1 2

    // 测试用例 2
    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int len2 = removeDuplicates(nums2);
    cout << "Test Case 2: ";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl; // 预期输出: 0 1 2 3 4

    // 测试用例 3
    vector<int> nums3 = {};
    int len3 = removeDuplicates(nums3);
    cout << "Test Case 3: ";
    for (int i = 0; i < len3; i++) {
        cout << nums3[i] << " ";
    }
    cout << endl; // 预期输出: （无输出）

    // 测试用例 4
    vector<int> nums4 = { 1, 1, 1, 1, 1 };
    int len4 = removeDuplicates(nums4);
    cout << "Test Case 4: ";
    for (int i = 0; i < len4; i++) {
        cout << nums4[i] << " ";
    }
    cout << endl; // 预期输出: 1
}

int main() {
    testRemoveDuplicates(); // 运行测试函数
    return 0;
}