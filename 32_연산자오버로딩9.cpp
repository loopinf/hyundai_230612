// 32_연산자오버로딩9.cpp
#include <iostream>
using namespace std;

// 1. 컴파일러는 사용자가 복사 생성자를 제공하지 않으면,
//    멤버를 복사하는 복사 생성자를 제공합니다.

// 2. 컴파일러는 사용자가 대입 연산자 오버로딩을 제공하지 않으면,
//    멤버를 복사하는 대입 연산자를 제공합니다.

// 3. 복사 생성자와 대입 연산자는 객체의 복사 정책을 결정합니다.
//  > 복사 생성자를 제공하면, 반드시 대입 연산자도 함께 제공해야 합니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    friend ostream& operator<<(ostream& os, const Point& pt)
    {
        return os << pt.x << ", " << pt.y;
    }

    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
    }

    // 대입연산자는 자기자신의 참조를 반환해야 합니다.
    Point& operator=(const Point& rhs)
    {
        x = rhs.x;
        y = rhs.y;

        return *this;
    }
};

int main()
{
    int a, b, c;
    a = b = c = 100;
    // c.operator=(100).operator=(c).operator=(b)

    Point pt1(10, 20);
    cout << pt1 << endl;

    Point pt2 = pt1; // 복사 생성자
    cout << pt2 << endl;

    Point pt3(30, 40);

    pt2 = pt3; // 대입 연산자
    // pt2.operator=(pt3);

    cout << pt2 << endl;
}
