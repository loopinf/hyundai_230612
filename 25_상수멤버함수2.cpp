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

    // 1. 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop()
    {
        return leftTop;
    }

    const Point& GetLeftTop() const
    {
        // Point leftTop => const Point leftTop;
        return leftTop;
    }

    // > 값으로 반환할 때는 const 반환이 필요하지 않습니다.
#if 0
    Point GetLeftTop() const
    {
        return leftTop;
    }
#endif
};

// 2. 상수 멤버 함수만 제공할 경우
//           Point p;   ---> 상수 멤버 함수
//     const Point p;   ---> 상수 멤버 함수
//    const Point& p;   ---> 상수 멤버 함수
//    const Point* p;   ---> 상수 멤버 함수

//   비상수 멤버 함수만 제공할 경우
//           Point p;   ---> 비상수 멤버 함수
//     const Point p;   ---> X
//    const Point& p;   ---> X
//    const Point* p;   ---> X

//   상수 멤버 함수 / 비상수 멤버 함수 모두 제공할 경우
//           Point p;   ---> 비상수 멤버 함수
//     const Point p;   ---> 상수 멤버 함수
//    const Point& p;   ---> 상수 멤버 함수
//    const Point* p;   ---> 상수 멤버 함수

int main()
{
    Rect rect;
    Point& r = rect.GetLeftTop();
    r.Move(100, 200);
    r.Print();

    const Rect rect2;
    // 불변 객체(Immutable Object)
    //  - 초기화 이후로 값을 변경할 수 없습니다.
    //  => 1) 값의 변경을 추적하는데 용이합니다.
    //     2) 멀티 스레드(동시성) 프로그래밍에서 객체에 동기화가 필요하지 않습니다.
    //  > 불변성을 지향하는 것은 좋을 때가 많습니다.

    const Point& r2 = rect2.GetLeftTop();
    // r2.Move(100, 200); // 상수 멤버 함수만 호출이 가능합니다.
    r2.Print();
}
