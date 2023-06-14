// 24_static.cpp
#include <iostream>
using namespace std;

#if 0
// 전역 변수는 접근 제어가 불가능합니다.
int cnt = 0;

class Car {
private:
    int color;

public:
    Car() { cnt++; }
    ~Car() { cnt--; }
};

int main()
{
    Car c1;
    Car c2;

    Car cars[5];

    cout << cnt << endl;
}
#endif

// Car.h
class Car {
private:
    int color;

public:
    static int cnt; // 정적 멤버 데이터

    Car() { cnt++; }
    ~Car() { cnt--; }
};

// 소스파일에 정적 멤버 데이터에 대한 정의가 반드시 필요합니다.
// Car.cpp
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
