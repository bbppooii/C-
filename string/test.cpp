#define _CRT_SECURE_NO_WARNINGS  // ���ð�ȫ����
#define string bit_string  // ������ std::string
#include <iostream>
#include <assert.h>


using namespace std;

    void test_string()
    {
        // ����Ĭ�Ϲ��캯��
        string s1;
        cout << "Ĭ�Ϲ�����ַ���: '" << s1 << "'����С: " << s1.size() << endl;
        assert(s1.size() == 0);  // ȷ����СΪ 0

        // ���Դ� C ����ַ�������
        string s2("Hello");
        cout << "��ʼ��Ϊ 'Hello' ���ַ���: '" << s2 << "'����С: " << s2.size() << endl;
        assert(s2.size() == 5);  // ȷ����СΪ 5
        assert(s2 == "Hello");  // ȷ���ַ���������ȷ

        // ���Կ������캯��
        string s3(s2);
        cout << "����������ַ���: '" << s3 << "'����С: " << s3.size() << endl;
        assert(s3 == s2);  // ȷ�����������������ͬ

        // ���Ը�ֵ�����
        string s4;
        s4 = s2;
        cout << "��ֵ���������ַ���: '" << s4 << "'����С: " << s4.size() << endl;
        assert(s4 == s2);  // ȷ����ֵ��������ͬ

        // ���� push_back �� append
        s1.push_back('H');
        s1.append("ello");
        cout << "ʹ�� push_back �� append ����ַ���: '" << s1 << "'����С: " << s1.size() << endl;
        assert(s1 == "Hello");  // ȷ����Ӳ�����ȷ

        // ���Բ�����+=
        s1 += ' ';
        s1 += "World";
        cout << "ʹ�� operator+= ����ַ���: '" << s1 << "'����С: " << s1.size() << endl;
        assert(s1 == "Hello World");  // ȷ�������� += ��ȷ

        //���� insert

    }


int main()
{
   test_string();  // ִ�в���
    cout << "���в���ͨ����" << endl;
    return 0;
}
