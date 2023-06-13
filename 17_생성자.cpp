// 17_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 제공하지 않으면,
//    컴파일러가 아무일도 수행하지 않는 인자 없는 생성자(기본 생성자)를 제공합니다.
//   Point() {}

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 생성자는 오버로딩이 가능합니다.

class Point {
private:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt; // Point()

    Point pt2(10, 20); // Point(int, int)
}
