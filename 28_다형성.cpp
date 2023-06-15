// 28_다형성.cpp
#include <iostream>
using namespace std;

class Animal { };

class Dog : public Animal { };
class Cat : public Animal { };

// Dog is an Animal
// Cat is an Animal
//  => 자식 클래스 is a 부모 클래스
//  => is-a 관계

int main()
{
    Animal* p;

    p = new Dog;
    p = new Cat;
}

#if 0
int main()
{
    Animal a;
    Dog d;

    Animal* pa = &a;
    Animal& ra = a;

    Dog* pd = &d;
    Dog& rd = d;

    // 부모의 포인터 / 참조 타입을 통해 자식의 객체를 참조할 수 있습니다.
    // => 자식의 주소(참조) 타입은 부모의 주소(참조) 타입으로의 암묵적인 변환을 허용합니다.
    //   : Upcasting
    Animal* pa2 = &d;
    Animal& ra2 = d;

    // 자식 클래스의 포인터 / 참조 타입은 부모 타입으로의 암묵적인 변환이 허용되지 않습니다.
    // => Downcasting은 암묵적인 변환이 허용되지 않습니다.

    // Dog* pd2 = &a; // error!
    // Dog& rd2 = a; // error!
}
#endif
