// 4_변수4.cpp
#include <iostream>
using namespace std;

// decltype - C++11
// => 초기화 없이, 지정된 변수와 동일한 타입의 변수를 만들 수 있습니다.
// => GNU extension의 'typeof'와 동일합니다.

int main()
{
    int n = 10;

    // n과 동일한 타입의 변수를 만들고 싶습니다.
    decltype(n) n2;

    const int c = 42;

    decltype(c) c2 = 100; // const int
    // c2 = 42;
}
