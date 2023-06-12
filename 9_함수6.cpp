// 9_함수6.cpp
#include <iostream>
using namespace std;

// 최대 공약수
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}
// 정수를 대상으로하는 함수이기 때문에,
// 실수가 인자로 전달될 경우, 오류를 발생시키고 싶습니다.
// "함수 금지"

// 핵심: 구현을 제공하지 않고, 선언만 제공합니다.
// double gcd(double a, double b);

// => 사용할 경우, 링크 오류를 발생시키는 의도입니다.
//  - 링크 오류는 의도를 전달하기 어렵습니다.
//    문제의 원인을 파악하기도 어렵습니다.
/*
Undefined symbols for architecture x86_64:
  "gcd(double, double)", referenced from:
      _main in 9_함수6-b9f48d.o
*/

// C++11에서 함수를 금지하는 문법이 도입되었습니다.
// - Delete function
// 9_함수6.cpp:35:13: error: call to deleted function 'gcd'
double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(15, 12) << endl;
    cout << gcd(25, 15) << endl;

    cout << gcd(3.14, 5.5) << endl;
}
