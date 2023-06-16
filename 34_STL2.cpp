// 34_STL2.cpp
#include <iostream>
using namespace std;

// 반복자(Iterator)
// : 배열에서 포인터의 역활과 유사합니다.

// 1) C++에서 구간을 표현할 때, 반개 구간을 사용합니다.
//   [begin, end)

#if 0
int main()
{
    //          p1            p2
    //           |             |
    int x[5] = { 1, 2, 3, 4, 5 };

    // int* p1 = &x[0];
    int* p1 = x;
    int* p2 = x + 5; // 끝 다음 위치, past the end

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

#include <list>
#include <deque>

// x.begin() : 컨테이너의 첫 원소를 가르키는 반복자
//   begin(x)

// x.end()   : 컨테이너의 마지막 원소 다음 위치를 가르키는 반복자
//   end(x)

int main()
{
    // int x[5] = { 1, 2, 3, 4, 5 };

    vector<int> x = { 1, 2, 3, 4, 5 };
    // list<int> x = { 1, 2, 3, 4, 5 };
    // deque<int> x = { 1, 2, 3, 4, 5 };

    // vector<int>::iterator
    auto p1 = begin(x); // 시작을 가르키는 반복자
    auto p2 = end(x); // 끝 다음(past the end)을 가르키는 반복자

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
