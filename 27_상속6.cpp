// 27_상속6.cpp
#include <iostream>
using namespace std;

// 의도: 부모 클래스의 객체 생성은 불가능하고,
//      자식 클래스의 객체 생성은 가능하게 하고 싶다.
//  => protected 생성자
//   - Animal을 추상 타입으로 사용하겠다.

class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal()
    {
    }
};
class Cat : public Animal { };

int main()
{
    // Animal a; // 잘못된 사용 - Animal::Animal()

    Dog d; // Dog::Dog()
    Cat c;
}
