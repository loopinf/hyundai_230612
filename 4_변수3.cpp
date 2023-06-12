// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 10;
    int* p1 = &n;

    int x[3] = { 10, 20, 30 };
    int* p2 = x;
    int(*p3)[3] = &x;
}
#endif

// C++11 - auto
// > 컴파일 타임에 우변의 타입을 기반으로 변수의 타입을 결정합니다.
// => 의존성 있는 타입을 다룰 때 편리하게 사용할 수 있습니다.
//  주의사항
//   - 우변의 타입을 통해 결정되기 때문에, 반드시 초기화가 필요합니다.
//   - C의 auto를 다른 의미로 사용합니다.

int main()
{
    int n = 10;
    auto p1 = &n;

    int x[3] = { 10, 20, 30 };
    auto p2 = x; // int*
    auto p3 = &x; // int(*)[3]

    // auto y; // 컴파일 오류!
}
