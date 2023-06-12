// 9_함수3.cpp
#include <iostream>
using namespace std;

// 주의사항

// 1) 반환타입만 다를 경우, 함수 오버로딩이 불가능합니다.
// int foo() { }
// void foo() { }

// 2) 파라미터 기본값과 사용할 때, 주의가 필요합니다.
//  - 파라미터 기본값과 오버로딩은 같이 사용하지 않습니다.
#if 0
void foo(int n = 100) { }
void foo() { }

int main()
{
    // foo(); // 모호합니다! 컴파일 오류!
}
#endif

// 아래 형태로 사용하는 것은 허용되지만,
// 사용방법이 동일하지 않은 형태로 오버로딩하는 경우는 거의 없습니다.
int foo(int n)
{
    return 0;
}

void foo()
{
}

int main()
{
    foo(10);
    foo();
}
