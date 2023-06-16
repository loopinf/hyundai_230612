// 34_STL3.cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 3. 알고리즘
//  : 컨테이너를 대상으로 탐색하고 정렬 알고리즘을 구현한
//    "일반 함수"

//  > 멤버 함수
//     list.find()
//   vector.find()

//  > 일반 함수                           알고리즘
//    list
//    vector  ======>  반복자     ======> find
//    array

#include <algorithm>

int main()
{
    //                              past the end
    //                                  |
    // int x[5] = { 10, 20, 30, 40, 50 };
    // vector<int> x = { 10, 20, 30, 40, 50 };

    list<int> x = { 10, 20, 30, 40, 50 };

    auto p = find(begin(x), end(x), 30);
    // 그 위치의 반복자를 반환합니다.

    // 알고리즘의 실패를 표현할 때,
    // past the end가 이용됩니다.
    if (p != end(x)) {
        cout << *p << endl; // !!!
    }
}
