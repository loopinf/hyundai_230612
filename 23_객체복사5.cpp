// 23_객체복사5.cpp
#include <iostream>
using namespace std;

class User {
    char* name;
    int age;

public:
    User(const User& rhs)
        : age(rhs.age)
    {
        cout << "User(const User&)" << endl;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // Move Constructor => 이동 생성자
    User(User&& rhs)
        : name(rhs.name)
        , age(rhs.age)
    {
        cout << "User(User&&)" << endl;
        rhs.name = nullptr;
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        cout << "~User()" << endl;
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

// 소유권 이전
// => rvalue reference

int main()
{
    // 임시 객체: User("Tom", 42) - rvalue

    // cout << "----" << endl;
    // User("Tom", 42);
    // cout << "----" << endl;

    User other(User("Tom", 42));
    // C++98: 임시 객체가 생성되고, 복사 생성자 호출
    // C++11: 임시 객체가 생성되고, 이동 생성자 호출
    // C++17: 불필요한 복사 생성자 / 이동 생성자 호출을 제거하는 것이
    //        기본입니다.
    //        "mandatory copy ellison"

    other.Print();
}

// C     => Go(켄 톰슨)
// C++   => Rust
// Java  => Kotlin
