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
int Square(int x)
{
    return x * x;
}

double Square(double x) { return x * x; }

int main()
{
    cout << Square(10) << endl;
    cout << Square(3.14) << endl;
}
