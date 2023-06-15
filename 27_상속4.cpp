// 27_상속4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; } // 3)
    ~Base() { cout << "~Base()" << endl; } // 4>
};

class Derived : public Base {
public:
    Derived()
    // : Base()    // 2) 초기화 리스트를 통해 부모의 기본 생성자가 호출됩니다. - Base::Base()
    {
        cout << "Derived()" << endl; // 4)
    }

    ~Derived()
    {
        cout << "~Derived()" << endl; // 2>
    } // 3> 자식의 소멸자의 마지막에 부모의 소멸자를 호출합니다. - Base::~Base()
};

/*
Base()
Derived()
~Derived()
~Base()
*/

int main()
{
    Derived d; // 1) Derived::Derived()
} // 1> Derived::~Derived()
