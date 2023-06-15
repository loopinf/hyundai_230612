// 25_상수멤버함수2.cpp
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
        cout << x << ", " << y << endl;
    }

    void Move(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Rect {
    Point leftTop;

public:
    Rect()
        : leftTop(10, 20)
    {
    }

    // 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop()
    {
        return leftTop;
    }

    const Point& GetLeftTop() const
    {
        // Point leftTop => const Point leftTop;
        return leftTop;
    }
};

int main()
{
    Rect rect;
    Point& r = rect.GetLeftTop();
    r.Move(100, 200);
    r.Print();

    const Rect rect2;
    const Point& r2 = rect2.GetLeftTop();
    // r2.Move(100, 200); // 상수 멤버 함수만 호출이 가능합니다.
    r2.Print();
}
