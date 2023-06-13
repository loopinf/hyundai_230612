// 16_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. private: 외부에서 접근이 불가능합니다.
//  - 자신의 멤버 함수를 통해서만 접근이 가능합니다.

// 2. public: 외부에서 접근이 가능합니다.
//     - struct: public
//     -  class: private

// 3. friend
//   > friend 선언된 함수와 클래스는 자신의 private 멤버에 접근이 가능합니다.

class User {
private:
    string name;
    int age;

public:
    User(string s, int n)
    {
        name = s;
        age = n;
    }

    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter {
public:
    void Print(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
}

int main()
{
    User user("Tom", 42);
    PrintUser(user);

    UserPrinter printer;
    printer.Print(user);
}
