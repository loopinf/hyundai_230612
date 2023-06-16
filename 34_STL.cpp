// 34_STL.cpp
#include <iostream>
using namespace std;

// STL(Standard Template Library)
// - 1979년: C++ 탄생
// - 1990년: C++ 표준 위원회 설립
// - 1998년: C++ 1차 표준안, STL 도입

// STL 구성 요소
//  1) 컨테이너: 데이터를 저장하기 위한 자료 구조
//   선형적인 자료구조: vector, list, array, deque
//     탐색 자료구조: map, set, unordered_map, unordered_set

//  2) 알고리즘
//    : 컨테이너의 요소를 검색, 정렬, 탐색, 이진 탐색 등의 알고리즘을 제공하는
//     "일반 함수"

//  3) 반복자
//    : 컨테이너의 요소를 열거하기 위해, 배열에서 포인터의 역활과 비슷하게 동작하는
//      객체입니다.

// 1. 컨테이너
//  1) 템플릿 기반입니다.
//   - 다양한 타입에 대해서 사용할 수 있습니다.

//  2) 멤버 함수의 이름이 유사합니다. > 자료 구조를 쉽게 전환할 수 있습니다.
//    |------------------------|
// push_front              push_back
//  pop_front              pop_back
//   front                   back

//  3) 자료구조마다 특성이 존재합니다.
//   - vector: 연속된 메모리
//     장점: 임의 접근 => a[10];
//     단점: push_front 지원하지 않습니다.

//   - list: 노드 기반 자료구조
//     단점: 임의 접근이 불가능합니다. => a[10] - 오류!
//     장점: 데이터의 삽입이 용이합니다.
//          push_front / push_back

#include <vector>
#include <list>

int main()
{
    vector<int> v = { 10, 20, 30, 40, 50 };

    // list는 임의 접근 연산을 사용할 수 없습니다.
    v[2] = 100;
    cout << v[2] << endl;

    // vector는 데이터를 앞에서 삽입할 수 없습니다.
    // v.push_front(100);

    list<int> l = { 10, 20, 30, 40, 50 };
    l.push_front(100);

    cout << l.front() << endl;
}

#if 0
int main()
{
    // vector<int> v = { 10, 20, 30, 40, 50 };
    list<int> v = { 10, 20, 30, 40, 50 };

    v.push_back(100);
    v.push_back(200);

    cout << v.back() << endl;
    v.pop_back();
}
#endif
