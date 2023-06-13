// 6_const.cpp
#include <iostream>
using namespace std;

// 1. C++에서 const 변수는 반드시 초기화가 필요합니다.

// 2. const 상수
//  C - 런타임 상수
//   > 값을 수정할 수 없지만, 값을 읽기 위해서는 변수의 메모리에 접근해서
//     읽어야 합니다.
//     "배열의 크기로 사용이 불가능합니다."

// C++ - 런타임 상수 / 컴파일 타임 상수
//   컴파일 타임 상수
//   => 컴파일 타임에 상수값이 결정됩니다. 실행 시간에 값을 변경할 수 없습니다.
//      상수에 대한 접근을 메모리를 이용하지 않습니다.
//    "배열의 크기로 사용이 가능합니다."

//   런타임 상수
//   => 실행 시간에 값을 변경할 수 없습니다.
//      상수에 대한 접근을 메모리를 이용합니다.
//    "배열의 크기로 사용이 불가능합니다."

// C++11 - constexpr
//  > 컴파일 상수에 대해서만 지정할 수 있습니다.

// int n;
//  : int

// int x[3];
//  : int[3]

int main()
{
    // const int c2; // 컴파일 오류!

    constexpr int n = 100; // 컴파일 타임 상수, const int
    // n = 42;

    int x;
    cin >> x;

    // constexpr int c2 = x; // 런타임 상수, constexpr 오류!
    const int c = x; // 런타임 상수
}
