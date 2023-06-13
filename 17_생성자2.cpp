// 17_생성자2.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc

class Point {
public:
    Point() { cout << "Point()" << endl; }
    Point(int a, int b) { cout << "Point(int, int)" << endl; }

    ~Point() { cout << "~Point()" << endl; }
};

// 1. malloc을 통해서 객체를 생성할 경우, 생성자가 호출되지 않습니다.
// 2. new를 통해서 객체를 생성할 경우, 생성자가 호출됩니다.
// 3. free를 통해서 객체의 메모리를 해지한 경우, 소멸자가 호출되지 않습니다.
// 4. delete를 통해서 객체의 메모리를 해지한 경우, 소멸자가 호출됩니다.

// new 연산자
// 1) 동적 메모리 할당
// 2) 객체라면, 생성자가 호출

// delete 연산자
// 1) 객체라면, 소멸자를 호출
// 2) 동적 메모리 해지

int main()
{
    cout << "main 시작" << endl;
    // Point pt(10, 20);

    // Point* pt = static_cast<Point*>(malloc(sizeof(Point)));
    // free(pt);

    Point* pt = new Point;
    delete pt;
}
