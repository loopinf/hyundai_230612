// 32_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

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

    ostream& operator<<(const char* s)
    {
        printf("%s", s);
        return *this;
    }

    ostream& operator<<(ostream& (*f)(ostream&))
    {
        f(*this);

        return *this;
    }
};

ostream cout;

ostream& endl(ostream& os)
{
    return os << '\n';
}

}

// 1. endl은 함수입니다.
//   - endl: IO Manipulator

// 2. ostream& endl(ostream& os) {}
//    endl(cout);

//    cout << endl;
//     원리: ostream& operator<<(ostream& (*f)(ostream&))

// 3. 다양한 활용이 가능합니다.

ostream& PrintMenu(ostream& os)
{
    os << "1. 자장면" << endl;
    os << "2. 짬뽕" << endl;
    os << "3. 탕수육" << endl;

    return os;
}

int main()
{
    // cout << "1. 자장면" << endl;
    // cout << "2. 짬뽕" << endl;
    // cout << "3. 탕수육" << endl;

    // PrintMenu(cout);
    cout << PrintMenu;
}

#if 0
int main()
{
    // cout << "hello" << endl;

    xstd::cout << "hello";
    xstd::cout << xstd::endl;
    // cout.operator<<(endl)
    //                 (ostream& (*f)(ostream&))

    // xendl(xstd::cout);
}
#endif
