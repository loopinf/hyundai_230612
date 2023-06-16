// 32_연산자오버로딩.cpp
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
    Complex Add(const Complex& rhs)
    {
        Complex result(re + rhs.re, im + rhs.im);
        return result;

        // return Complex(re + rhs.re, im + rhs.im);
    }

    friend Complex Add(const Complex& lhs, const Complex& rhs);
};

// 2) 일반 함수
Complex Add(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs.re + rhs.re, lhs.im + rhs.im);
    return result;
}

int main()
{
    Complex c1(10, 5);
    c1.Print();

    Complex c2(20, 3);
    c2.Print();

    // 복소수 합 연산: c1 + c2
    // 1) 멤버 함수
    Complex result1 = c1.Add(c2);
    result1.Print();

    // 2) 일반 함수
    Complex result2 = Add(c1, c2);
    result2.Print();
}
