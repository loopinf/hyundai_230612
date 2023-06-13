// 11_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Inc1(int x)
{
    ++x;
}

void Inc2(int* px)
{
    ++(*px);
}

void Inc3(int& r)
{
    ++r;
}

int main(void)
{
    int n = 10;
    Inc1(n); // Call by Value
    cout << n << endl;

    Inc2(&n); // Call by Pointer
    cout << n << endl;

    Inc3(n); // Call by Reference
    cout << n << endl;
}
