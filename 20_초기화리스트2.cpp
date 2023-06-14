// 20_초기화리스트2.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
#if 0
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }
#endif
    // Point()
    //     : x(0)
    //     , y(0)
    // {
    // }

    // Uniform Initialization
    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

// 1. 사용자가 생성자를 제공하지 않는 경우,
//    아무일도 수행하지 않는 기본 생성자를 제공합니다.
//
// 2. 컴파일러가 제공하는 기본 생성자 형태
//    Rect() : leftTop(), rightBottom()
//    {}

// 3. 초기화 리스트를 제공해야 하는 경우
//   1) 멤버의 타입이 const
//   2) 멤버의 타입이 reference
//   3) 멤버 객체가 기본 생성자를 제공하지 않을 때

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    Rect()
        : leftTop(10, 20) // Point::Point(int, int)
        , rightBottom(40, 50) // Point::Point(int, int)
    {
    }
};

int main()
{
    Point pt(10, 20);
    pt.Print();

    Rect rect;
}
