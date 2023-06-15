// 28_다형성5.cpp
#include <iostream>
using namespace std;

// 1) 반드시 부모의 멤버 함수가 가상함수 이어야 합니다.
//    가상 함수가 아닌 멤버 함수는 오버라이딩 하지 않습니다.

// 2) virtual
//  - 부모의 멤버 함수가 가상함수이면, 자식도 가상함수입니다.

// 3) 문제점
//  1) 부모의 함수의 이름을 잘못 사용하였을 때를 알 수 없습니다.
//  2) 반드시 가상 함수에 대해서만 오버라이딩 해야 합니다.
//     그래야 부모의 포인터(참조) 타입을 통해 해당 기능을 이용할 수 있습니다.
//  => C++11, override

class Car {
public:
    virtual void Start() const { cout << "Car::Start()" << endl; }
};

class Sedan : public Car {
public:
    // virtual void Start() const { cout << "Sedan::Start()" << endl; }
    void Start() const override { cout << "Sedan::Start()" << endl; }
};

int main()
{
    Sedan s;
    Car* p = &s;

    //  - dynamic, virtual
    p->Start(); // "다형성"
    // p의 실제 객체가 Car 타입이면, Car::Start()
    //            Sedan 타입이면, Sedan::Start()
}

// Unix / Linux
//  => VFS(Virtual File System)

// "다형성(polymorphism)"
//  open / read / write / close  ------> 일반 파일          ---> 일반 파일 처리
//                                      디바이스 특수 파일    ---> 장치 제어
//                                       소켓 파일          ---> 네트워크
