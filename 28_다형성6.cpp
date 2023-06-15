// 28_다형성6.cpp
#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() const { cout << "Car::Start" << endl; }
};

class Sedan : public Car {
public:
    // 모든 세단은 아래 함수를 통해 Start가 수행되어야 합니다.
    // -> 오버라이딩 금지
    //    C++11, final
    void Start() const override final { cout << "Sedan::Start" << endl; }
};

class Avante : public Sedan {
public:
    // > 오류! final 멤버 함수는 오버라이딩이 허용되지 않습니다.
    // void Start() const override { cout << "Avante::Start" << endl; }
};

int main()
{
    Avante avante;
    avante.Start();
}
