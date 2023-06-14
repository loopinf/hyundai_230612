// 23_객체복사.cpp
#include <iostream>
using namespace std;

//  2) 참조 계수
class User {
    char* name;
    int age;

    int* ref;

public:
    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
        , ref(rhs.ref)
    {
        // 핵심: 복사가 수행되면, 참조 계수 증가 해야 합니다.
        ++(*ref);
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int(1); // !!
    }

    ~User()
    {
        // 참조 계수가 0이 되면, 자원을 정리합니다.
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }

        cout << "Ref: " << Ref() << endl;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }

    int Ref()
    {
        return *ref;
    }
};

int main()
{
    User user("Tom", 42);
    cout << "Ref: " << user.Ref() << endl; // 1

    user.Print();

    User other = user;
    cout << "Ref: " << user.Ref() << endl; // 1

    other.Print();
}
