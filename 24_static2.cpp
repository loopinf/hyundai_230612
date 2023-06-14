// 24_static2.cpp
#include <iostream>
using namespace std;

class Car {
private:
    int color;

    static int cnt; // 정적 멤버 데이터
public:
    Car() { cnt++; }
    ~Car() { cnt--; }

    // int GetCount() { return cnt; }
    // 멤버 함수는 반드시 객체를 통해서만 호출할수 있습니다.

    // 정적 멤버 함수
    // > 전역 함수와 동일한데, 접근 제어가 가능합니다.
    // - 객체가 생성되지 않아도, 호출이 가능합니다.
    static int GetCount() { return cnt; }
};

int Car::cnt = 0;

int main()
{
    // 정적 멤버 함수
    // 1. 클래스
    cout << Car::GetCount() << endl;

    Car c1;
    Car c2;

    Car cars[5];

    // 2. 객체
    cout << c1.GetCount() << endl;
}
