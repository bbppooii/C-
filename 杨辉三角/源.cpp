#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows); // 初始化外层 vector 的大小为 numRows

        // 初始化每一行
        for (size_t i = 0; i < numRows; ++i) {
            vv[i].resize(i + 1, 0); // 每一行的大小为 i + 1，初始化为 0
            vv[i][0] = vv[i][vv[i].size() - 1] = 1; // 每一行的第一个和最后一个元素为 1
        }

        // 填充内部元素
        for (size_t i = 2; i < vv.size(); ++i) { // 从第 3 行开始（i = 2）
            for (size_t j = 1; j < vv[i].size() - 1; ++j) { // 从第 2 列到倒数第 2 列
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1]; // 当前元素等于上一行的 j 和 j-1 元素之和
            }
        }

        return vv;
    }
};

// 打印杨辉三角
void printPascalTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// 测试函数
void testGenerate(int numRows) {
    Solution solution;
    cout << "Input: numRows = " << numRows << endl;
    vector<vector<int>> result = solution.generate(numRows);
    cout << "Output:" << endl;
    printPascalTriangle(result);
    cout << "-----------------------------" << endl;
}

int main() {
    // 测试用例
    testGenerate(1);  // 测试 1 行
    testGenerate(2);  // 测试 2 行
    testGenerate(5);  // 测试 5 行
    testGenerate(10); // 测试 10 行

    return 0;
}