// 17_생성자3.cpp
#include <iostream>
using namespace std;

class Point {
public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
};

// 1. 멤버 데이터의 생성자가 호출되고, 객체의 생성자가 호출됩니다.
// 2. 객체의 소멸자가 먼저 호출되고, 멤버 데이터의 소멸자가 호출됩니다.

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    Rect()
    // 2) leftTop 생성자 호출
    // 3) rightBottom 생성자 호출
    {
        cout << "Rect()" << endl; // 4)
    }

    ~Rect()
    {
        cout << "~Rect()" << endl; // 2>

        // 3> rightBottom 소멸자 호출
        // 4> leftTop 소멸자 호출
    }
};

int main()
{
    Rect r; // 1) Rect::Rect()

} // 1> Rect::~Rect()
