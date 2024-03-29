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

    string address;

public:
    Person(const string& name, int age, const string& phone)
        : name_(name)
        , age_(age)
        , phone_(phone)
    {
        Init();
    }

    void SetAddress(const std::string& address)
    {
        // 멤버의 이름과 인자의 이름이 동일하면, 인자의 이름이 멤버의 이름을 가립니다.

        // 반드시 this를 명시해서 사용해야 합니다.
        this->address = address;
    }

    Person(const string& name)
        : Person(name, 0, "") // 위임생성자, 초기화리스트에서 사용해야 합니다.
    {
    }

// 위임 생성자: 생성자에서 다른 생성자를 통해 초기화를 수행할 수 있습니다. => C++11
//   - 생성자 코드의 불필요한 코드 중복을 제거할 수 있습니다.
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
