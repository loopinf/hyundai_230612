// 27_상속5.cpp
#include <iostream>
#include <string>
using namespace std;

// 생성자에서 초기화리스트를 반드시 제공해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 멤버 클래스가 기본 생성자를 제공되지 않는 경우
// 4) 부모 클래스가 기본 생성자를 제공하지 않는 경우

#if 0
class Animal {
    int age;

public:
    Animal(int n)
        : age(n)
    {
    }
};

// 핵심: 부모 클래스가 기본 생성자를 제공하지 않는 경우,
//      명시적으로 초기화리스트를 통해 부모의 클래스를 초기화해주어야 합니다.
class Dog : public Animal {
public:
    // Dog() : Animal() {} => 컴파일러가 제공하는 기본 생성자 형태

    Dog()
        : Animal(42)
    {
    }
};

int main()
{
    Dog d;
}
#endif

class Animal {
    string name;
    int age;

public:
    Animal(const string& s, int n)
        : name(s)
        , age(n)
    {
    }
};

// 자식 클래스는 부모의 클래스를 초기화하는데 필요한 데이터를
// 같이 처리해야 합니다.
class Dog : public Animal {
    int color;

public:
    Dog(const string& s, int n, int c)
        : Animal(s, n)
        , color(c)
    {
    }
};

int main()
{
    Dog d("Alice", 5, 1000);
}
