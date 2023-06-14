// 20_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해하는 것이 중요합니다.
// 2. C++에서 반드시 초기화가 필요한 것
//   1) const
//   2) 레퍼런스

// 3. 생성자에서 멤버 데이터를 초기화하기 위해서는
//    "초기화 리스트" 문법을 이용해야 합니다.
//   > 초기화 리스트는 생성자 함수에서만 사용이 가능합니다.

// 4. 멤버 데이터의 타입이 const / 레퍼런스 인 경우에는 반드시
//    초기화리스트를 통해 초기화를 해야 합니다.

class Sample {
    const int x;
    int& y;

public:
#if 0
    Sample(int a, int& r)
    {
        x = a; // 초기화가 아닌 대입
        y = r; // 초기화가 아닌 대입
    }
#endif

    Sample(int a, int& r)
        : x(a)
        , y(r)
    {
    }
};

int main()
{
}

#if 0
int main()
{
    int a = 10; // 초기화

    int b;
    b = 10; // 대입

    // const int c; // 반드시 초기화가 필요합니다.
    const int c = 100;

    // int& r; // 반드시 초기화가 필요합니다.
    int& r = a;
}
#endif
