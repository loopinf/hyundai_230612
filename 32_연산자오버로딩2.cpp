// 32_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

class Complex {
    int re;
    int im;

public:
    Complex(int r, int i)
        : re(r)
        , im(i)
    {
    }

    void Print() const { cout << re << " + " << im << "i" << endl; }

// 1) 멤버 함수
#if 0
    Complex operator+(const Complex& rhs)
    {
        Complex result(re + rhs.re, im + rhs.im);
        return result;

        // return Complex(re + rhs.re, im + rhs.im);
    }
#endif

    friend Complex operator+(const Complex& lhs, const Complex& rhs);
};

// 2) 일반 함수
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs.re + rhs.re, lhs.im + rhs.im);
    return result;
}

// 연산자 오버로딩
//  정의: 객체를 대상으로 연산자를 사용하였을 경우,
//       약속된 이름의 멤버 함수 / 일반 함수가 호출됩니다.
//   => 사용자는 연산자를 통해 객체의 함수를 호출할 수 있습니다.

int main()
{
    Complex c1(10, 5);
    c1.Print();

    Complex c2(20, 3);
    c2.Print();

    // 복소수 합 연산: c1 + c2
    // 1) 멤버 함수
    Complex result1 = c1 + c2;
    // result1 = c1.operator+(c2);

    result1.Print();

    // 2) 일반 함수
    Complex result2 = c1 + c2;
    // result2 = operator+(c1, c2);

    result2.Print();
}
