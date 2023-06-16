// 32_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Integer {
    int value;

public:
    Integer(int n = 0)
        : value(n)
    {
    }

    // 일반 함수
    friend ostream& operator<<(ostream& os, const Integer& i)
    {
        return os << i.value;
    }

    Integer& operator++()
    {
        ++value;
        return *this;
    }
};

int main()
{
    int n1 = 42;
    ++ ++n1;
    //   C: 증가된 값
    // C++: 자기 자신의 참조

    cout << n1 << endl;

    Integer n2 = 42;
    ++ ++n2;
    // n2.operator++().operator++()

    cout << n2 << endl;
}
