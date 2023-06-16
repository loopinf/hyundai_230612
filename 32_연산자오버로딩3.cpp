// 32_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

// cout: 표준 출력 객체
//  cin: 표준 입력 객체

// cout의 실제 클래스 타입은 ostream
namespace xstd {

class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(char ch)
    {
        printf("%c", ch);
        return *this;
    }
};

ostream cout;

}

int main()
{
    int n = 42;
    xstd::cout << n;
    // xstd::cout.operator<<(n);

    char ch = 'X';
    xstd::cout << ch;
    // xstd::cout.operator<<(ch);

    xstd::cout << n << ch;
    // cout.operator<<(n).operator<<(ch);
}
