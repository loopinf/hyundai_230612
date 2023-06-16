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
#if 1
    Complex operator+(const Complex& rhs)
    {
        cout << "멤버 함수" << endl;
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
    cout << "일반 함수" << endl;
    Complex result(lhs.re + rhs.re, lhs.im + rhs.im);
    return result;
}

// 연산자 오버로딩
//  정의: 객체를 대상으로 연산자를 사용하였을 경우,
//       약속된 이름의 멤버 함수 / 일반 함수가 호출됩니다.
//   => 사용자는 연산자를 통해 객체의 함수를 호출할 수 있습니다.

// 1) 연산자 우선 순위는 변경되지 않습니다.
//    a + (b * c);

// 2) 피연산자의 개수도 변경되지 않습니다.
//    c1 + c2  : 이항 연산자
//     : c1.operator+(c2)
//       operator+(c1, c2)
//    ++c1: 단항 연산장
//       c1.operator++()

// 3) 새로운 연산자를 제공할 수 없습니다.
// 4) 연산자 오버로딩이 허용되지 않는 연산자도 있습니다.
//   - ::(범위 연산자), .(접근 연산자), .*(멤버 함수 포인터 접근 연산자)
//     (expr)? statement1:statement2 (3항 연산자)

// 5) 반드시 피연산자 중 하나는 사용자 정의 타입이어야 합니다.
//   int operator+(int a, int b) => 허용 X
//   int operator+(int a, const Point& pt) => 허용 O

// 6) 반드시 멤버 함수를 통해서만 제공되어야 하는 연산자가 있습니다.
//   > 클래스의 제작자만 제공할 수 있습니다.
//   1) 대입 연산자
//     a = b;
//   2) 함수 호출 연산자
//     f();
//   3) 임의 접근 연산자
//     arr[0], arr[1]
//   4) ->
//     p->age = 42;
//   5) 포인터 참조 연산자
//     *p

int main()
{
    Complex c1(10, 5);
    c1.Print();

    Complex c2(20, 3);
    c2.Print();

    // 복소수 합 연산: c1 + c2
    // 1) 멤버 함수: 클래스를 설계한 제작자만 추가할 수 있습니다.
    Complex result1 = c1 + c2;
    // result1 = c1.operator+(c2);

    result1.Print();

    // 2) 일반 함수: 클래스의 제작자가 아닌 사람도 추가할 수 있습니다.
    Complex result2 = c1 + c2;
    // result2 = operator+(c1, c2);

    result2.Print();
}
