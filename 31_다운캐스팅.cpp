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

class Cat : public Animal {
    int color;

public:
    Cat()
        : color(100)
    {
    }
};

int main()
{
    // Animal* p = new Dog;
    Animal* p = new Cat;

    // 부모의 포인터 p를 통해서는 Dog의 name에 접근이 불가능합니다.
    cout << p->GetAge() << endl;

    // cout << p->GetName() << endl;
    // 1. 부모의 포인터 / 참조를 통해 자식 객체의 속성에 접근하기 위해서는
    //    자식 타입으로의 명시적인 변환이 필요합니다.
    //    > "다운 캐스팅"

    // 2. 다운 캐스팅
    //   - 부모 타입 객체나 다른 자식 타입 객체일 때
    //     미정의 동작이 발생할 수 있습니다.
    //   > 실행 시간에 타입의 조사가 필요합니다.
    //     * RTTI(Run Time Type Information)
    //      => typeid 연산자
    //     1) typeid(클래스) => type_info 구조체
    //     2) typeid(객체)  => type_info 구조체
    //    if (typeid(클래스) == typeid(객체)) { "객체는 클래스 타입입니다." }

    // p가 Dog 타입인지 조사해서
    if (typeid(*p) == typeid(Dog)) {
        cout << "객체는 Dog 타입입니다." << endl;
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetName() << endl;
    } else {
        cout << "객체는 Dog 타입이 아닙니다." << endl;
    }

    //  * dynamic_cast 캐스팅 연산자
    Dog* pDog = dynamic_cast<Dog*>(p);
    // p가 Dog 타입인지 실행시간에 조사해서, 아니면 nullptr을 반환합니다.
    if (pDog) {
        cout << "객체는 Dog 타입입니다." << endl;
        cout << pDog->GetName() << endl;
    } else {
        cout << "객체는 Dog 타입이 아닙니다." << endl;
    }
}
