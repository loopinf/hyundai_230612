// 9_함수5.cpp
#include <iostream>
using namespace std;

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }
// > 타입만 다르고, 알고리즘은 동일합니다.
// => C++에서는 컴파일러가 전달된 인자를 기반으로 함수를 자동으로 생성하는
//    기술을 이용하면 편리합니다.
//   "Template"
//   : 컴파일러가 컴파일 시간에 코드를 생성합니다.
// 1) 컴파일러가 인자를 통해 코드를 자동으로 생성합니다.
// 2) 컴파일 시간이 늘어납니다.
// 3) 다양한 타입에 대해서 동작하는 일반적인 함수를 만들 수 있습니다.
// 4) 전달된 인자의 타입의 종류만큼의 코드를 생성하기 때문에
//    코드 메모리 사용량이 증가할 수 있습니다.
//   - 인라인 최적화가 수행된다면, 메모리 사용량을 최적화할 수 있습니다.

// C++ 표준 라이브러리
// => STL(Standard Template Library)

template <typename T>
T square(T x) { return x * x; }

int main()
{
    cout << square(10) << endl; // T -> int
    cout << square(3.14) << endl; // T -> double
    cout << square(1000000LL) << endl; // T -> long long

    // cout << square(3.14F) << endl; // T -> float : 암시적 추론
    cout << square<double>(3.14F) << endl;
    // T -> double : 명시적인 타입 지정
}
