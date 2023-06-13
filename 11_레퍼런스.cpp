// 11_레퍼런스.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 10;
    int* p = &n;

    *p = 100;
    cout << *p << endl;
}
#endif

#if 1
int main()
{
    int n = 10;
    int* p = NULL;

    // 레퍼런스: 기존 메모리에 새로운 이름(별명)을 부여합니다.
    int& r = n;

    // int& r2;
    // - 반드시 초기화가 필요합니다.
    // - NULL 레퍼런스 개념은 존재하지 않습니다.

    r = 100;
    cout << r << endl;
}
#endif
