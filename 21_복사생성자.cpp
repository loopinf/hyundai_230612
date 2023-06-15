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

//  3) 복사 생성자: 자신과 동일한 타입의 객체를 통해 객체를 생성할 때 호출되는 생성자

class Sample { };
// 1) 기본 생성자
// 2) 복사 생성자

class Sample2 {
public:
    Sample2(const Sample2& rhs) { }
};
// 복사 생성자도 생성자이기 때문에, 컴파일러는 기본 생성자를 제공하지 않습니다.

int main()
{
    // Sample2 x;

    Sample s1;
    Sample s2(s1);

    Point pt1(10, 20); // Point::Point(int, int)
    pt1.Print();

    Point pt2 = pt1; // Point::Point(const Point&)
    pt2.Print();

    Point pt3(pt1); // Point::Point(const Point&)
    pt3.Print();

    // Uniform Initialization
    Point pt4 { pt1 }; // Point::Point(const Point&)
    pt4.Print();

    Point pt5 = { pt1 }; // Point::Point(const Point&)
    pt5.Print();
}
