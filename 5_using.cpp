// 5_using.cpp
#include <iostream>
using namespace std;

// using 용도
// 1) namespace
//   - using 선언
//     using std::cout;

//   - using 지시어
//     using namespace std;

// 2) using - C++11
//    Type aliasing
//    => typedef를 대체합니다.

#if 0
typedef int AGE; // AGE == int
typedef int ARR[3]; // ARR == int[3]

// 배열 포인터, 함수 포인터
typedef int (*PARR)[3]; // PARR == int(*)[3]
typedef int (*FP)(int, int); // FP == int(*)(int, int)

int Add(int a, int b) { return a + b; }

int main()
{
    AGE age; // int age;
    ARR arr; // int arr[3];

    PARR p = &arr;
    FP fp = &Add;
}
#endif

using AGE = int;
using ARR = int[3];

// 배열 포인터, 함수 포인터
using PARR = int (*)[3];
using FP = int (*)(int, int);

int Add(int a, int b) { return a + b; }

int main()
{
    AGE age; // int age;
    ARR arr; // int arr[3];

    PARR p = &arr;
    FP fp = &Add;
}
