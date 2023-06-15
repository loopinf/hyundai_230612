// 25_상수멤버함수.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    void Print() const
    {
        // int x ==> const int x;
        // int y ==> const int y;
        cout << x << ", " << y << endl;

        // x = 10;
        // y = 20;
    }
};

// 1. const T / const T* / const T&
//  => 멤버 함수 안에서 데이터의 변경이 발생할 수 있기 때문에,
//     일반적인 멤버 함수는 호출이 불가능합니다.
//     "상수 멤버 함수"

// 2. 상수 멤버 함수
//  : 멤버 함수 안에서 멤버 데이터를 상수 취급합니다.
//    멤버 함수 안에서 멤버 데이터의 값을 변경할 수 없습니다.

// 3. 멤버 함수 안에서 멤버 데이터의 값을 변경하지 않는 경우,
//    반드시 상수 멤버 함수로 만들어야 합니다.

void PrintPoint(const Point& pt)
{
    pt.Print(); // 상수 멤버 함수만 호출이 가능합니다.
}

int main()
{
    Point pt(10, 20);
    pt.Print();

    const Point pt2(10, 20);
    pt2.Print();

    const Point* p = &pt;
    p->Print();

    const Point& r = pt;
    r.Print();
}
