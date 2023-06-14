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

int main()
{
    Point pt(10, 20);
    pt.Print();
}
