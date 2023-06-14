// 22_위임생성자.cpp
#include <iostream>
#include <string>
using namespace std;

// 멤버 데이터의 이름 규칙
//  1) m_name
//  2) mName
//  3) name_
//  4) _name => 표준 라이브러리가 내부적으로 사용하는 이름 규칙

class Person {
private:
    string name_;
    int age_;
    string phone_;

    void Init() { cout << "초기화" << endl; }

public:
    Person(const string& name, int age, const string& phone)
        : name_(name)
        , age_(age)
        , phone_(phone)
    {
        Init();
    }

    Person(const string& name)
        : Person(name, 0, "")
    {
    }

// 위임 생성자: 생성자에서 다른 생성자를 통해 초기화를 수행할 수 있습니다. => C++11
#if 0
    Person(const string& name)
        : name_(name)
        , age_(0)
        , phone_("")
    {
        Init();
    }
#endif
};

int main()
{
    Person person("Tom", 42, "000-111-2222");

    Person person2("Bob");
}
