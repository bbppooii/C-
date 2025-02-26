#define _CRT_SECURE_NO_WARNINGS  // 禁用安全警告
#define string bit_string  // 重命名 std::string
#include <iostream>
#include <assert.h>


using namespace std;

    void test_string()
    {
        // 测试默认构造函数
        string s1;
        cout << "默认构造的字符串: '" << s1 << "'，大小: " << s1.size() << endl;
        assert(s1.size() == 0);  // 确保大小为 0

        // 测试从 C 风格字符串构造
        string s2("Hello");
        cout << "初始化为 'Hello' 的字符串: '" << s2 << "'，大小: " << s2.size() << endl;
        assert(s2.size() == 5);  // 确保大小为 5
        assert(s2 == "Hello");  // 确保字符串内容正确

        // 测试拷贝构造函数
        string s3(s2);
        cout << "拷贝构造的字符串: '" << s3 << "'，大小: " << s3.size() << endl;
        assert(s3 == s2);  // 确保拷贝构造后内容相同

        // 测试赋值运算符
        string s4;
        s4 = s2;
        cout << "赋值运算符后的字符串: '" << s4 << "'，大小: " << s4.size() << endl;
        assert(s4 == s2);  // 确保赋值后内容相同

        // 测试 push_back 和 append
        s1.push_back('H');
        s1.append("ello");
        cout << "使用 push_back 和 append 后的字符串: '" << s1 << "'，大小: " << s1.size() << endl;
        assert(s1 == "Hello");  // 确保添加操作正确

        // 测试操作符+=
        s1 += ' ';
        s1 += "World";
        cout << "使用 operator+= 后的字符串: '" << s1 << "'，大小: " << s1.size() << endl;
        assert(s1 == "Hello World");  // 确保操作符 += 正确

        //测试 insert

    }


int main()
{
   test_string();  // 执行测试
    cout << "所有测试通过！" << endl;
    return 0;
}
