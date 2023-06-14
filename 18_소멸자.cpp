// 18_소멸자.cpp
#include <iostream>
using namespace std;

#include <cstring>

// 1. 객체 내부에서 자원을 할당하고 있으면,
//    반드시 소멸자를 통해서 자원을 해지해야 합니다.

// 2. 소멸자를 정의하지 않으면, 컴파일러는 아무일도 수행하지 않는
//    소멸자를 자동으로 제공합니다.

// 3. 소멸자의 형태
//    : ~클래스이름()
//    => 오버로딩도 불가능하고, 인자도 전달받지 않습니다.

class Person {
    char* name;

public:
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print() { cout << name << endl; }

    ~Person()
    {
        delete[] name;
    }
};

int main()
{
    Person person("Tom");
    person.Print();
}
