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
    cout << sizeof(A) << endl; // 输出非静态成员变量所占用的内存大小
    A::B b;
    A aa;
    b.foo(aa); // 输出_static成员和非静态成员
    return 0;
}
