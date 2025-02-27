#include <iostream>
#include <vector>
using namespace std;

// ����һ��ȫ�ֺ��������������Ա����
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0; // �������Ϊ�գ�ֱ�ӷ��� 0
    }

    size_t newLength = 1; // ������ĳ��ȣ���ʼΪ 1����һ��Ԫ�ؿ϶����ظ���
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) { // �����ǰԪ����ǰһ��Ԫ�ز�ͬ
            nums[newLength++] = nums[i]; // ����ǰԪ�طŵ����������һ��λ��
        }
    }

    return newLength; // ����������ĳ���
}

// ���Ժ���
void testRemoveDuplicates() {
    // �������� 1
    vector<int> nums1 = { 1, 1, 2 };
    int len1 = removeDuplicates(nums1);
    cout << "Test Case 1: ";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl; // Ԥ�����: 1 2

    // �������� 2
    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int len2 = removeDuplicates(nums2);
    cout << "Test Case 2: ";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl; // Ԥ�����: 0 1 2 3 4

    // �������� 3
    vector<int> nums3 = {};
    int len3 = removeDuplicates(nums3);
    cout << "Test Case 3: ";
    for (int i = 0; i < len3; i++) {
        cout << nums3[i] << " ";
    }
    cout << endl; // Ԥ�����: ���������

    // �������� 4
    vector<int> nums4 = { 1, 1, 1, 1, 1 };
    int len4 = removeDuplicates(nums4);
    cout << "Test Case 4: ";
    for (int i = 0; i < len4; i++) {
        cout << nums4[i] << " ";
    }
    cout << endl; // Ԥ�����: 1
}

int main() {
    testRemoveDuplicates(); // ���в��Ժ���
    return 0;
}