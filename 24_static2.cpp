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
    //  - 객체의 주소가 전달됩니다.(this)

    // 정적 멤버 함수 / 정적 메소드 / 클래스 메소드
    // > 전역 함수와 동일한데, 접근 제어가 가능합니다.
    // - 객체가 생성되지 않아도, 호출이 가능합니다.
    // - this가 전달되지 않습니다.
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
