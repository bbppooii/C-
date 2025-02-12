#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };
		for (auto ch : s) {
			count[ch - 'a']++;
		}
		for (size_t i = 0; i < s.size(); i++) {
			if (count[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	solution sol;

	// ʾ������
	cout << sol.firstUniqChar("leetcode") << endl;  // ��� 0
	cout << sol.firstUniqChar("loveleetcode") << endl;  // ��� 2
	cout << sol.firstUniqChar("aabb") << endl;  // ��� -1

	return 0;
}