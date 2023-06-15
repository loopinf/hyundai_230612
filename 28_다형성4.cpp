// 28_다형성4.cpp
#include <iostream>
using namespace std;

// 1. 부모의 멤버 함수를 자식 클래스가 재정의 할 수 있습니다.
//   "함수 오버라이딩(Overriding)"

class Car {
public:
    virtual void Start() const { cout << "Car::Start()" << endl; }
};

class Sedan : public Car {
public:
    virtual void Start() const { cout << "Sedan::Start()" << endl; }
};

// 2. 함수 바인딩(Binding)
//   p->Start();
// 1. 정적 바인딩(static binding)
//   : 컴파일 타임에 컴파일러가 결정합니다.
//     컴파일러가 컴파일 타임에 p의 타입을 보고 어떤 함수를 호출할지 결정합니다.

// 2. 동적 바인딩(dynamic binding)
//   : 실행 시간에 결정합니다.
//     컴파일러가 p가 실행중에 어떤 타입의 객체를 가지고 있는지 조사해서
//     함수를 호출하는 코드를 삽입합니다.

int main()
{
    Car car;
    Sedan sedan;

    Car* p = &car;
    p->Start();

    p = &sedan;
    p->Start();

    Car& r1 = car;
    r1.Start();

    Car& r2 = sedan;
    r2.Start();
}

#if 0
int main()
{
    Car car;
    car.Start();

    Sedan sedan;
    sedan.Start();
}
#endif
