// 9_함수3.cpp
#include <iostream>
using namespace std;

// 주의사항

// 1) 반환타입만 다를 경우, 함수 오버로딩이 불가능합니다.
// int foo() { }
// void foo() { }

// 2) 파라미터 기본값과 사용할 때, 주의가 필요합니다.
// 파라미터 기본값
void foo(int n = 100) { }
void foo() { }

int main()
{
    // foo(); // 모호합니다! 컴파일 오류!
}
