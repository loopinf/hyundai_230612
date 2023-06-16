// 32_연산자오버로딩5.cpp
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

    friend ostream& operator<<(ostream& os, const Point& pt);
    friend istream& operator>>(istream& is, Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;

    // return os;
}

istream& operator>>(istream& is, Point& pt)
{
    return is >> pt.x >> pt.y;
}

int main()
{
    // int n = 10;
    // cout << n;
    // cout.operator<<(n); => 멤버 함수

    Point pt(10, 20);

    cout << pt << endl;
    // operator<<(cout, pt); => 일반 함수

    cin >> pt;
    // cin.operator>>(pt);
    // operator>>(cin, pt);

    cout << pt << endl;
}
