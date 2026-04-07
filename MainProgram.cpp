#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

class MyString {
private:
    string data;

public:
    MyString() { data = ""; }
    MyString(const string& str) { data = str; }
    MyString(const char* str) { data = string(str); }

    string getData() const { return data; }

    int length() const {
        return static_cast<int>(data.length());
    }

    char charAt(int index) const {
        if (index < 0 || index >= (int)data.length())
            throw out_of_range("Index out of range");
        return data[index];
    }

    MyString substring(int start, int len) const {
        if (start < 0 || start >= (int)data.length())
            throw out_of_range("Start index out of range");
        return MyString(data.substr(start, len));
    }

    MyString toUpperCase() const {
        string result = data;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return MyString(result);
    }

    MyString toLowerCase() const {
        string result = data;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return MyString(result);
    }

    MyString trim() const {
        size_t start = data.find_first_not_of(" \t\n\r");
        size_t end = data.find_last_not_of(" \t\n\r");

        if (start == string::npos) return MyString("");

        return MyString(data.substr(start, end - start + 1));
    }

    MyString reverse() const {
        string result = data;
        std::reverse(result.begin(), result.end());
        return MyString(result);
    }

    int find(const MyString& target) const {
        size_t pos = data.find(target.data);
        if (pos == string::npos) return -1;
        return static_cast<int>(pos);
    }

    int count(char ch) const {
        int cnt = 0;
        for (char c : data) {
            if (c == ch) cnt++;
        }
        return cnt;
    }

    MyString append(const MyString& other) const {
        return MyString(data + other.data);
    }

    MyString append(const char* cstr) const {
        return MyString(data + string(cstr));
    }

    MyString append(char ch) const {
        return MyString(data + ch);
    }

    MyString append(int number) const {
        return MyString(data + to_string(number));
    }

    MyString replace(char oldCh, char newCh) const {
        string result = data;
        for (char& c : result) {
            if (c == oldCh) c = newCh;
        }
        return MyString(result);
    }

    MyString replace(const string& oldStr, const string& newStr) const {
        string result = data;
        size_t pos = 0;
        while ((pos = result.find(oldStr, pos)) != string::npos) {
            result.replace(pos, oldStr.length(), newStr);
            pos += newStr.length();
        }
        return MyString(result);
    }

    MyString operator+(const MyString& other) const {
        return MyString(data + other.data);
    }

    bool operator==(const MyString& other) const {
        return data == other.data;
    }

    char operator[](int index) const {
        if (index < 0 || index >= (int)data.length())
            throw out_of_range("Index out of range");
        return data[index];
    }

    MyString operator*(int times) const {
        if (times <= 0) return MyString("");
        string result;
        for (int i = 0; i < times; i++) {
            result += data;
        }
        return MyString(result);
    }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.data;
        return os;
    }
};

int main() {
    MyString s1(" Hello World ");

    cout << "Original: [" << s1 << "]" << endl;
    cout << "Trim: [" << s1.trim() << "]" << endl;
    cout << "Upper: " << s1.toUpperCase() << endl;
    cout << "Lower: " << s1.toLowerCase() << endl;
    cout << "Reverse: " << s1.reverse() << endl;
    cout << "Length: " << s1.length() << endl;

    return 0;
}
