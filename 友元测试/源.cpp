#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A {
private:
    static int _k;
    int _h = 1;

public:
    class B {
    public:
        void foo(const A& a) {
            cout << _k << endl; // OK
            cout << a._h << endl; // OK
        }
    };
};

int A::_k = 1;

int main() {
    cout << sizeof(A) << endl; // ����Ǿ�̬��Ա������ռ�õ��ڴ��С
    A::B b;
    A aa;
    b.foo(aa); // ���_static��Ա�ͷǾ�̬��Ա
    return 0;
}
