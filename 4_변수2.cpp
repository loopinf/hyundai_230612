// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = { 1, 2, 3 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3] { 1, 2, 3 };
    Point pt2 { 10, 20 };
}
