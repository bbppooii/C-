#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows); // ��ʼ����� vector �Ĵ�СΪ numRows

        // ��ʼ��ÿһ��
        for (size_t i = 0; i < numRows; ++i) {
            vv[i].resize(i + 1, 0); // ÿһ�еĴ�СΪ i + 1����ʼ��Ϊ 0
            vv[i][0] = vv[i][vv[i].size() - 1] = 1; // ÿһ�еĵ�һ�������һ��Ԫ��Ϊ 1
        }

        // ����ڲ�Ԫ��
        for (size_t i = 2; i < vv.size(); ++i) { // �ӵ� 3 �п�ʼ��i = 2��
            for (size_t j = 1; j < vv[i].size() - 1; ++j) { // �ӵ� 2 �е������� 2 ��
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1]; // ��ǰԪ�ص�����һ�е� j �� j-1 Ԫ��֮��
            }
        }

        return vv;
    }
};

// ��ӡ�������
void printPascalTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// ���Ժ���
void testGenerate(int numRows) {
    Solution solution;
    cout << "Input: numRows = " << numRows << endl;
    vector<vector<int>> result = solution.generate(numRows);
    cout << "Output:" << endl;
    printPascalTriangle(result);
    cout << "-----------------------------" << endl;
}

int main() {
    // ��������
    testGenerate(1);  // ���� 1 ��
    testGenerate(2);  // ���� 2 ��
    testGenerate(5);  // ���� 5 ��
    testGenerate(10); // ���� 10 ��

    return 0;
}