// 9_함수2.cpp
#include <iostream>
using namespace std;

// C에서는 동일한 이름의 함수를 여러개 만들 수 없습니다.
#if 0
int Squarei(int x) { return x * x; }
double Squared(double x) { return x * x; }

int main()
{
    cout << Squarei(10) << endl;
    cout << Squared(3.14) << endl;
}
#endif

// C++에서는 동일한 이름의 함수를 여러개 만들 수 있습니다.
// > 인자 정보가 다른 경우 만들 수 있습니다.
// "함수 오버로딩(Overloading, 중복 적재)"

// 원리 => Name mangling
// : C++의 컴파일러는 함수의 이름에 인자정보가 포함됩니다.
// 1) 함수의 반환값으로는 함수 오버로딩이 불가능합니다.
// 2) C++ 컴파일러와 C의 컴파일러는 함수의 이름을 결정하는 방식이 다릅니다.
//  > C++ 프로그램에서 C의 함수를 호출하거나,
//    C 프로그램에서 C++의 함수를 호출하는 것이 일반적으로는 불가능합니다.
//     : extern "C" - 선언부
//    - C++에서 함수를 C의 형태로 만들 수 있습니다.
//    - C++에서 C의 함수를 호출할 수 있습니다.

// 0000000100003d70 T __Z6Squarei
int Square(int x)
{
    return x * x;
}

// 0000000100003d80 T __Z6Squared
double Square(double x) { return x * x; }

int main()
{
    cout << Square(10) << endl;
    cout << Square(3.14) << endl;
}
