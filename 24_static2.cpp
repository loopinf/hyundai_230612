// 24_static2.cpp
#include <iostream>
using namespace std;

class Car {
private:
    int color;

public:
    static int cnt; // 정적 멤버 데이터

    Car() { cnt++; }
    ~Car() { cnt--; }
};

int Car::cnt = 0;

int main()
{
    Car c1;
    Car c2;

    Car cars[5];

    // 정적 멤버 데이터에 접근하는 방법
    // 1) 클래스
    cout << Car::cnt << endl;

    // 2) 객체
    cout << c1.cnt << endl;
    cout << c2.cnt << endl;
}
