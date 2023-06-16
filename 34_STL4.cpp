// 34_STL4.cpp
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm> // sort

// 정책을 만드는 방법
// 1) 일반 함수
bool cmp(int a, int b) { return a > b; }

// 2) 함수 객체
// : 함수 호출 연산자를 재정의한 클래스의 객체
class Compare {
public:
    bool operator()(int a, int b) const { return a > b; }
};

int main()
{
    vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    // sort(begin(v), end(v), cmp); // 템플릿
    //               bool (*)(int, int) => 일반 함수 정책
    //               : 인라인 함수라도, 함수 포인터를 통해 호출하면, 인라인 최적화가 불가능합니다.

    Compare cmp2;
    // sort(begin(v), end(v), cmp2);
    //                    Compare => 함수 객체가 정책으로 전달되면, 인라인 최적화가 가능합니다.

    // C++11, 람다 표현식
    // > 익명의 함수 객체를 생성하는 문법
    sort(begin(v), end(v), [](int a, int b) { return a > b; });

    // 내림차순 정렬
    // => sort는 비교 정책을 세번째 인자로 전달받습니다.

    for (auto e : v) {
        cout << e << endl;
    }
}
