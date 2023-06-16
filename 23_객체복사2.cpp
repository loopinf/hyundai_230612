// 23_객체복사2.cpp
#include <iostream>
using namespace std;

//  1) 깊은 복사(Deep copy)

class User {
    char* name;
    int age;

public:
    //-------
    User(const User& rhs)
        : age(rhs.age)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // int a = 10;
    // a = a;
    User& operator=(const User& rhs)
    {
        // 1. 자신과 동일한 객체인지 체크합니다.
        if (this == &rhs) {
            return *this;
        }

        // 2. 자원을 해지합니다.
        delete[] name;

        // 3. 깊은 복사를 수행합니다.
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);

        age = rhs.age;

        return *this;
    }

    //-------

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
