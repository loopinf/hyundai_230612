// 11_레퍼런스4.cpp
#include <iostream>
using namespace std;

// C++ 레퍼런스
// 1. & - lvalue reference
//    > lvalue를 참조할 수 있습니다.
//    - 수정 가능한 lvalue
//      int n;

//    - 수정 불가능한 lvalue
//      const int c;

// 2. && - rvalue reference, C++11
//    > rvalue를 참조할 수 있습니다.

// a = 3;

// lvalue: 좌변에 올수 있는 것
//        > 특정 메모리 위치를 참조하는 표현식입니다.
//          모든 lvalue는 메모리 주소가 할당되어 있으므로, & 연산자를 이용해서
//          해당 주소를 가져올 수 있습니다.

// rvalue: 좌변에 올수 없는 것
//        > 일회용 임시 대상체를 참조하는 표현식입니다.
//          생성된 위치에서 조작할 수 없고, 소멸됩니다.
//          주소를 취할수 없습니다.

#if 0
int main()
{
    int a;
    int b;
    a = 3;
    // a: lvalue
    // 3: rvalue

    int& r1 = a;
    // int& r2 = 3;

    int&& r3 = 3;

    const int c = 42;

    cout << &a << endl; // OK => lvalue
    cout << &c << endl; // OK => lvalue

    // cout << &10 << endl; => rvalue

    // c = 100;
}
#endif

// C++98/03
// void foo(const int& r)
// {
//     cout << r << endl;
// }

// 필요에 따라서, lvalue와 rvalue를 다르게 처리해야 하는 경우가 있습니다.

#if 0
void foo(int& r)
{
    cout << "lvalue" << endl;
}

void foo(int&& r)
{
    cout << "rvalue" << endl;
}

int main()
{
    int n = 100;

    int& r = n;
    int&& rr = 100;

    foo(n);
    foo(100);

    // const lvalue reference
    // => lvalue, rvalue 모두 참조할 수 있습니다.
    const int& cr1 = n; /* OK */
    const int& cr2 = 100; /* OK */
}
#endif

#include <cstring>

struct User {
    char name[32];

public:
    User(const char* s)
    {
        strcpy(name, s);
    }
};

// 1) User& => 함수를 통해서 수정될 수 있습니다.
// 2) rvalue를 처리할 수 없습니다.
// void PrintUser(User& user)

void PrintUser(const User& user)
{
    cout << user.name << endl;
}
// const T& => const lvalue reference
//           : lvalue와 rvalue를 모두 참조할 수 있습니다.
//  : lvalue와 rvalue를 구분해서 처리할수 없습니다.
//  해결방법 - C++11, rvalue reference

void PrintUser(User&& user)
{
    cout << "rvalue: " << user.name << endl;
}

int main()
{
    // User user = { "Tom" }; - 구조체
    User user("Tom");

    PrintUser(user);
    PrintUser(User("Tom")); // User("Tom"): 임시 객체 생성 문법 - rvalue
}
