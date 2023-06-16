// 31_다운캐스팅.cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
    int age;

public:
    Animal()
        : age(42)
    {
    }

    virtual ~Animal() { }

    int GetAge() const { return age; }
};

class Dog : public Animal {
    string name;

public:
    Dog()
        : name("Bob")
    {
    }

    string GetName() const { return name; }
};

int main()
{
}
