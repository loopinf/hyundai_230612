// 32_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

namespace xstd {

class istream {
public:
    istream& operator>>(int& n)
    {
        scanf("%d", &n);
        return *this;
    }
};

istream cin;

}

int main()
{
    int n, x;
    xstd::cin >> n >> x;
    // cin.operator>>(n).operator>>(x)

    cout << n << x << endl;
}
