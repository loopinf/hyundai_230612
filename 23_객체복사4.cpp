// 23_객체복사4.cpp
#include <iostream>
using namespace std;

// 3) 복사 금지

class User {
    char* name;
    int age;

    // 1) private 영역에 선언만 합니다. - C++98/03
    // User(const User& rhs);

public:
    // 2) delete function - 복사 생성자 금지 / C++11
    User(const User& rhs) = delete;

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user("Tom", 42);
    user.Print();

    // User other = user; - 컴파일 오류!
    // other.Print();
}
