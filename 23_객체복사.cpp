// 23_객체복사.cpp
#include <iostream>
using namespace std;

// 핵심
// - 클래스가 포인터 멤버 데이터를 가지는 경우,
//   컴파일러가 자동으로 제공하는 복사 생성자는
//   오류의 원인이 됩니다.
//   => 얕은 복사(Shallow Copy)
// 해결 방법
//   => 복사 생성자를 직접 정의해서, 문제를 해결해야 합니다.
//    1) 깊은 복사
//    2) 참조 계수
//    3) 복사 금지

class User {
    char* name;
    int age;

public:
    // 컴파일러가 자동으로 생성하는 복사 생성자
    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
    {
        cout << "복사 생성자" << endl;
    }

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

    User other = user;
    other.Print();
}
