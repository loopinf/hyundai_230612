// 15_stack10.cpp
#include <iostream>
using namespace std;

#include <stack>
// 표준 라이브러리(STL)에 이미 스택이 제공됩니다.
// 템플릿 기반으로 제공됩니다.

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 제거하는 연산과, 데이터를 참조하는 연산이
    // 분리되어 있습니다.
    // - 제거: s.pop()
    // - 참조: s.top()
    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
