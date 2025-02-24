#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string input;
    vector<string>arr;
    while (cin >> input) {
        arr.push_back(input);
    }
    cout << arr[arr.size() - 1].length() << endl;
    return 0;
}