// 9_함수4.cpp
#include <iostream>
using namespace std;

// 1. C 에서는 함수 호출의 오버헤드를 제거하기 위해서
//    매크로 함수를 사용합니다.
//   > 전처리기의한 텍스트 치환
//     우선순위 문제가 발생하지 않도록, 치환 영역을 괄호로 감싸주어야 합니다.
#define SQUARE(x) ((x) * (x))
//  => 미정의 동작의 위험성이 존재하기 때문에
//     ++, -- 연산을 같이 사용하는 것은 위험합니다.

#if 0
int main()
{
    int a = 10;
    cout << SQUARE(a) << endl;
    // cout << ((a) * (a)) << endl;

    ++a;
    cout << SQUARE(a) << endl;

    // cout << SQUARE(++a) << endl; // 위험합니다.
    // cout << ((++a) * (++a)) << endl; // 미정의 동작
}
#endif

// 2. C++ 에서는 함수 호출의 오버헤드를 제거하기 위해서,
//    매크로 함수가 아닌 inline 함수를 사용해야 합니다.
inline int Square(int x) { return x * x; }
// > 텍스트 치환이 아닌 기계어 치환의 형태로 동작합니다.

// 인라인 함수
// 1) 컴파일 최적화 명령입니다.
//   MSVC: /Ob1
// 2) 기계어 치환의 코드가 복잡하다면,
//    전체 프로그램의 사이즈가 커지는 문제가 발생할 수 있습니다.
//   > 최신 컴파일러는 함수의 기계어 사이즈가 크다면,
//     인라인 함수의 최적화를 수행하지 않습니다.
//   > 간결한 함수에 대해서만 사용해야 합니다.
//   - C99 표준에서도, 인라인 함수가 도입되었습니다.
//   static inline void foo() {} - C99
//          inline void foo() {} - C++

int main()
{
    int a = 10;
    cout << Square(++a) << endl;
}
