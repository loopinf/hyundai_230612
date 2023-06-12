// 7_struct.cpp
#include <iostream>
using namespace std;

struct Point {
    double x;
    int y;
    int z;
};

int main()
{
    Point pt = { 10, 20 };

    // int x = pt.x;
    // int y = pt.y;
    auto [x, y, z] = pt;

    cout << x << ", " << y << endl;

    // C++17, Structured Binding 선언
    // 1) auto를 반드시 사용해야 합니다.
    // 2) 멤버 데이터의 개수와 동일하게 지정되어야 합니다.
    // 3) 배열에서도 사용이 가능합니다.
    int arr[3] = { 10, 20, 30 };
    auto [x1, x2, x3] = arr;

    cout << x1 << ", " << x2 << ", " << x3 << endl;
}
