#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace bit {
    const size_t string::npos = -1;

    string::iterator string::begin() {
        return _str;
    }

    string::iterator string::end() {
        return _str + _size;
    }

    string::const_iterator string::begin() const {
        return _str;
    }

    string::const_iterator string::end() const {
        return _str + _size;
    }

    string::string(const char* str)
        : _size(strlen(str)) {
        _str = new char[_size + 1];
        _capacity = _size;
        strcpy(_str, str);
    }

    string::string(const string& s) {
        _str = new char[s._size + 1];
        strcpy(_str, s._str);
        _size = s._size;
        _capacity = s._capacity;
    }

    string& string::operator=(const string& s) {
        if (this != &s) {
            char* tmp = new char[s._capacity + 1];
            strcpy(tmp, s._str);
            delete[] _str;
            _str = tmp;
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }

    string::~string() {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    const char* string::c_str() const {
        return _str;
    }

    size_t string::size() const {
        return _size;
    }

    char& string::operator[](size_t pos) {
        assert(pos < _size);
        return _str[pos];
    }

    const char& string::operator[](size_t pos) const {
        assert(pos < _size);
        return _str[pos];
    }

    void string::reserve(size_t n) {
        if (n > _capacity) {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }

    void string::push_back(size_t ch) {
        insert(_size, ch);
    }

    void string::append(const char* str) {
        insert(_size, str);
    }

    string& string::operator+=(char ch) {
        push_back(ch);
        return *this;
    }

    string& string::operator+=(const char* str) {
        append(str);
        return *this;
    }

    void string::insert(size_t pos, char ch) {
        assert(pos <= _size);
        if (_size == _capacity) {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
            reserve(newcapacity);
        }

        for (size_t end = _size; end > pos; --end) {
            _str[end] = _str[end - 1];
        }
        _str[pos] = ch;
        ++_size;
    }

    void string::insert(size_t pos, const char* str) {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity) {
            reserve(_size + len);
        }

        for (size_t end = _size - 1; end >= pos; --end) {
            _str[end + len] = _str[end];
        }
        memcpy(_str + pos, str, len);
        _size += len;
    }

    void string::erase(size_t pos, size_t len) {
        assert(pos < _size);
        if (len >= _size - pos) {
            _str[pos] = '\0';
            _size = pos;
        }
        else {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }

    size_t string::find(char ch, size_t pos) {
        for (size_t i = pos; i < _size; i++) {
            if (_str[i] == ch) {
                return i;
            }
        }
        return npos;
    }

    size_t string::find(const char* str, size_t pos) {
        char* p = strstr(_str + pos, str);
        if (p != nullptr) {
            return p - _str;
        }
        return npos;
    }

    void string::swap(string& s) {
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);
    }

    string string::substr(size_t pos, size_t len) {
        if (pos >= _size) {
            return string();  // 返回空字符串
        }

        if (len > _size - pos) {
            len = _size - pos;  // 确保len不会超过剩余的字符长度
        }

        string sub;
        sub.reserve(len);
        for (size_t i = 0; i < len; i++) {
            sub += _str[pos + i];
        }
        return sub;
    }

    bool string::operator<(const string& s) const {
        return strcmp(_str, s._str) < 0;
    }

    bool string::operator>(const string& s) const {
        return !(*this <= s);
    }

    bool string::operator<=(const string& s) const {
        return *this < s || *this == s;
    }

    bool string::operator>=(const string& s) const {
        return *this > s || *this == s;
    }

    bool string::operator==(const string& s) const {
        return strcmp(_str, s._str) == 0;
    }

    bool string::operator!=(const string& s) const {
        return !(*this == s);
    }

    void string::clear() {
        _str[0] = '\0';
        _size = 0;
    }

    istream& operator>>(istream& is, string& str) {
        str.clear();
        char ch = is.get();
        while (ch != ' ' && ch != '\n' && ch != EOF) {
            str += ch;
            ch = is.get();
        }
        return is;
    }

    ostream& operator<<(ostream& os, string& str) {
        for (size_t i = 0; i < str.size(); i++) {
            os << str[i];
        }
        return os;
    }
}
