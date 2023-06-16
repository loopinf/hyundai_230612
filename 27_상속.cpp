// 27_상속.cpp
#include <iostream>
#include <string>
using namespace std;

// 상속: 객체 지향 설계의 핵심적인 문법중 하나입니다.

#if 0
class Dog {
    int color;
    int age;
    string name;
    string owner;

public:
    int GetColor() const { return color; }
    int GetAge() const { return age; }
    string GetName() const { return name; }

    string GetOwner() const { return owner; }
};

class Cat {
    int color;
    int age;
    string name;
    string address;

public:
    int GetColor() const { return color; }
    int GetAge() const { return age; }
    string GetName() const { return name; }

    string GetAddress() const { return address; }
};

int main()
{
    Dog d;
    Cat c;

    d.GetAge();
    d.GetColor();
    d.GetName();

    d.GetOwner();

    c.GetAge();
    c.GetColor();
    c.GetName();

    c.GetAddress();
}
#endif

// Dog와 Cat의 공통의 멤버를 가집니다.
class Animal {
    int color;
    int age;
    string name;

public:
    int GetColor() const
    {
        cout << "Animal::GetColor()" << endl;
        return color;
    }

    int GetAge() const { return age; }
    string GetName() const { return name; }
};

// class Dog : public Animal
// => 상속
//  Dog는 Animal의 속성(멤버 데이터 / 멤버 함수)를 상속 받습니다.

// class Dog : public Animal
//            --------
//            접근 변경자
//              => 오직 C++에만 존재합니다.
//            protected / private 상속: 객체지향의 범용적인 상속의 개념과 다릅니다.

class Dog : public Animal {
    string owner;

public:
    string GetOwner() const { return owner; }
};

class Cat : public Animal {
    string address;

public:
    string GetAddress() const { return address; }
};

int main()
{
    Dog d;
    Cat c;

    d.GetAge();
    d.GetColor();
    d.GetName();

    d.GetOwner();

    c.GetAge();
    c.GetColor();
    c.GetName();

    c.GetAddress();
}
