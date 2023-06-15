// 28_다형성4.cpp
#include <iostream>
using namespace std;

// 1. 부모의 멤버 함수를 자식 클래스가 재정의 할 수 있습니다.
//   "함수 오버라이딩(Overriding)"

class Car {
public:
    void Start() const { cout << "Car::Start()" << endl; }
};

class Sedan : public Car {
public:
    void Start() const { cout << "Sedan::Start()" << endl; }
};

int main()
{
    Car car;
    car.Start();

    Sedan sedan;
    sedan.Start();
}
