// 29_다형성2.cpp
#include <iostream>
using namespace std;

class Animal {
    int age;

public:
    Animal()
        : age(42)
    {
    }

    int GetAge() const { return age; }
};

class Dog : public Animal { };
class Cat : public Animal { };

#if 0
void PrintAge(const Dog& dog)
{
    cout << dog.GetAge() << endl;
}

void PrintAge(const Cat& cat)
{
    cout << cat.GetAge() << endl;
}
#endif

class Rabbit : public Animal { };

// 1. 동종을 처리하는 함수
//  : Animal을 상속받는 모든 자식 클래스의 객체는 해당 함수를 이용할 수 있습니다.
void PrintAge(const Animal& animal)
{
    cout << animal.GetAge() << endl;
}

void PrintAge(const Animal* p)
{
    cout << p->GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);
    PrintAge(&d);

    Cat c;
    PrintAge(c);
    PrintAge(&c);

    Rabbit r;
    PrintAge(r);
    PrintAge(&r);
}
