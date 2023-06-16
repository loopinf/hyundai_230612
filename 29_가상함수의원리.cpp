// 29_가상함수의원리.cpp
#include <iostream>
using namespace std;

// 1. 클래스에 가상 함수가 1개라도 존재한다면,
//    포인터 크기 만큼 객체의 크기가 증가합니다.
//   > 가상 함수 테이블을 참조합니다.

// 2. 가상 함수 비용
//  1) 가상 함수를 가지는 모든 객체의 크기는 가상 함수 테이블 포인터 크기(8바이트) 만큼 늘어납니다.
//  2) 가상 함수를 가지는 클래스의 가상 함수 테이블 비용
//      => 클래스 * 가상 함수 개수

class Animal {
    int age;

public:
    virtual void Go() const { }
    virtual void Start() { }
};

class Dog : public Animal {
    int color;
    int speed;

public:
    void Go() const override { }
};

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Go();

    p = &d;
    p->Go();
}

#if 0
int main()
{
    Animal a;
    cout << sizeof(a) << endl;

    Dog d;
    cout << sizeof(d) << endl;
}
#endif
