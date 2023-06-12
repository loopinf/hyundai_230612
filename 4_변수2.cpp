// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
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

    // C++11 - Uniform Initialization(일관된 초기화)
    // - Copy Initialization
    int n3 = { 42 };
    int x3[3] = { 1, 2, 3 };
    Point pt3 = { 10, 20 };

    // - Direct Initialization
    int n4 { 42 };
    int x4[3] { 1, 2, 3 };
    Point pt4 { 10, 20 };
}
#endif

// Uniform Initialization
// => Preventing Narrow

int main()
{
    double d = 3.14;
    // int n = d;

    // 실수 타입이 정수 타입으로의 암묵적인 변환을 허용하지 않습니다.
    // int n = { (int)d };

    // int n(d);
    int n { (int)d };
    cout << n << endl;

    // 더 큰 표현 범위를 작은 표현 범위의 정수로의 암묵적인 변환을 허용하지 않습니다.
    long long ll = 420000000000LL; // 64비트 정수 타입입니다.
    // int n2 = ll;
    int n2 = { (int)ll };

    cout << n2 << endl;
}
