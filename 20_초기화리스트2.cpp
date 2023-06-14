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

    // 객체 멤버가 초기화되는 순서는 멤버 데이터가 선언된 순서대로 초기화됩니다.
    Point leftTop;
    Point rightBottom;

public:
    // 초기화리스트를 작성할 때, 멤버 데이터가 선언된 순서대로 작성하는 것이
    // 좋습니다.
    Rect(int x1, int y1, int x2, int y2)
        : leftTop(x1, y1) // Point::Point(int, int)
        , rightBottom(x2, y2) // Point::Point(int, int)
    {
    }

    void Print()
    {
        leftTop.Print();
        rightBottom.Print();
    }
};

int main()
{
    Point pt(10, 20);
    pt.Print();

    Rect rect(10, 20, 30, 40);
    rect.Print();
}
