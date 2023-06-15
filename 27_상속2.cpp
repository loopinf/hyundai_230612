// 27_상속2.cpp
#include <iostream>
using namespace std;

// 1. 상속 받는 방법
//   class 자식클래스 : public 부모클래스

// 2. Animal: 부모, Base, Super
//       Dog: 자식, Derived, Sub

// 3. 자식 클래스는 부모 클래스의 멤버를 물려 받습니다.

class Animal {
    int age;
};

class Dog : public Animal {
    int color;
};

int main()
{
    Animal a;
    cout << sizeof(a) << endl;

    Dog d;
    cout << sizeof(d) << endl; // 8
}
