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

    Integer operator++(int)
    {
        Integer temp(*this); // 현재 상태를 복사합니다.
        ++value;

        return temp;
    }
};

int main()
{
    int n1 = 42;
    ++ ++n1;
    //   C: 증가된 값
    // C++: 자기 자신의 참조

    n1++;
    // n1은 증가하고, 증가되기 이전의 값

    cout << n1 << endl;

    Integer n2 = 42;
    ++ ++n2;
    // n2.operator++().operator++()

    n2++;
    // n2.operator++(int): dummy
    // n2는 증가하고, 증가되기 이전의 값

    cout << n2 << endl;
}
