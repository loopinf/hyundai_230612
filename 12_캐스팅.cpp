// 12_캐스팅.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc

void foo(char* s)
{
    printf("%s\n", s);
}

// 캐스팅: 명시적으로 타입간의 변환을 위해 사용합니다.
//  C의 캐스팅은 용도와 목적이 달라도, 동일한 형태를 가지고 있기 때문에
//  파악하기 어렵다.
//  => C++은 캐스팅의 용도/목적에 따라서 4가지의 캐스팅 연산자를 제공합니다.
//  1) static_cast
//   : 가장 기본적인 C++의 캐스팅 연산자 입니다.
//     컴파일 타임에 캐스팅을 수행하기 때문에, 이름이 static_cast 입니다.
//     - 실수 타입을 정수 타입으로 변환할 때
//     - 더 넓은 표현 범위를 가지는 정수 타입을 더 적은 표현 범위의 정수 타입으로 변환할 때
//     - void*를 구체적인 포인터 타입으로 변환할 때

//  2) reinterpret_cast
//   : 메모리를 재해석하는 용도로 사용합니다.
//    => 위험한 캐스팅 연산자 입니다.

//  3) const_cast
//   : 메모리의 상수성(const)를 제거하는 목적으로 사용합니다.
//    => 타입의 불일치 문제를 해결하기 위해 사용해야 합니다.

//  4) dynamic_cast
//   : 실행 시간에 타입을 조사해서, 해당하는 타입이 아닌 경우
//     nullptr을 반환합니다.
#if 1
int main()
{
    // Uniform Initialization: Preventing Narrow
    double d = 3.14;
    int n { static_cast<int>(d) };

    long long ll = 42LL;
    int x { static_cast<int>(ll) };

    int* pn = static_cast<int*>(malloc(sizeof(int)));
    //------

    // 메모리 재해석 => 위험합니다.
    int v = 0x12345678;
    // char* pv = static_cast<char*>(&v);  /* 오류 */
    char* pv = reinterpret_cast<char*>(&v);
    printf("%x %x %x %x\n", pv[0], pv[1], pv[2], pv[3]);

    // double* pd = (double*)&v;
    // *pd = 3.14; /* 미정의 동작 */

    char str[32] = "hello";
    foo(str);

    // const T -> T
    const char* s = "hello";
    foo(const_cast<char*>(s));

    // foo(static_cast<char*>(s));
    // foo(reinterpret_cast<char*>(s));
}
#endif

#if 0
int main()
{
    // Uniform Initialization: Preventing Narrow
    double d = 3.14;
    int n { (int)d };

    long long ll = 42LL;
    int x { (int)ll };

    int* pn = (int*)malloc(sizeof(int));
    // C에서는 void*를 구체적인 포인터타입으로의 암묵적인 변환을 허용하지만,
    // C++은 허용하지 않습니다.

    // 메모리 재해석
    int v = 0x12345678;
    char* pv = (char*)&v;
    // 포인터의 타입은 포인터 연산의 단위를 결정합니다.
    // int* p;
    //   => p + N => p + sizeof(int) * N

    printf("%x %x %x %x\n", pv[0], pv[1], pv[2], pv[3]);

    char str[32] = "hello";
    foo(str);

    // const T -> T
    const char* s = "hello";
    foo((char*)s);
}
#endif
