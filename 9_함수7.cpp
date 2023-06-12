// 9_함수7.cpp
#include <iostream>
using namespace std;

// int Add(int a, int b) { return a + b; }

// C++11에서 함수를 만드는 새로운 문법이 도입되었습니다.
// "Trailing Return Type"
auto Add(int a, int b) -> int { return a + b; }

// 1) 직관적이다.
// using PARR = int (*)[3];
// PARR foo()

// int (*foo())[3]
auto foo() -> int (*)[3]
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int (*)[3]
}

// using FP = int (*)(int, int);
// FP goo()

// int (*goo())(int, int)
auto goo() -> int (*)(int, int)
{
    return &Add; // int (*)(int, int)
}

// 2) 반환 타입을 추론할 수 있습니다.
// auto Sub(int a, int b) -> int { return a - b; }
auto Sub(int a, int b) { return a - b; }

// 3) decltype(a*b) => 인자의 연산의 결과를 통해 타입을 결정합니다.
// - decltype(a * b) Mul(int a, int b) { return a * b; }

auto Mul(int a, int b) -> decltype(a * b) { return a * b; }

int main()
{
    cout << Add(10, 20) << endl;
    cout << Sub(10, 20) << endl;
}
