// 21_복사생성자.cpp
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
        cout << "Point(int, int)" << endl;
    }

    // 컴파일러가 만들어주는 복사 생성자 형태
    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
        cout << "Point(const Point&)" << endl;
    }

    void Print() { cout << x << ", " << y << endl; }
};

// class Point {};
//  1) 사용자가 생성자를 아무것도 제공하지 않으면, 컴파일러가 기본 생성자를 제공합니다.
//  2) 사용자가 복사 생성자를 제공하지 않으면, 컴파일러가 멤버를 복사하는 복사 생성자를
//     제공합니다.

int main()
{
    Point pt1(10, 20); // Point::Point(int, int)
    pt1.Print();

    Point pt2 = pt1; // Point::Point(const Point&)
    pt2.Print();

    Point pt3(pt1); // Point::Point(const Point&)
    pt3.Print();
}
