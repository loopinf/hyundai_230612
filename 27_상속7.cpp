// 27_상속7.cpp

#include <iostream>
#include <vector>
using namespace std;

// stack을 만들고 싶습니다.
//  : 이미 잘 만들어진 vector를 활용해서,
//    stack을 만들어봅시다.

// Adapter Pattern
//  : 기존 클래스를 인터페이스를 변경해서,
//    새로운 클래스처럼 사용할 수 있습니다.

// 잘못 사용하기 어렵게 설계되어야 합니다.
// - public 상속
//   : 부모의 모든 구현과 인터페이스를 물려 받습니다.

// - protected 상속 / private 상속
//   : 부모의 구현은 사용하지만, 외부에 공개하지 않을 때, "즉 인터페이스는 물려 받지 않겠다"는 의도
//  protected 상속
//    부모 public  --> protected
//  private 상속
//    부모 protected -> private
//    부모 public    -> private

#if 0
template <typename TYPE>
class Stack : private vector<TYPE> {
public:
    void push(const TYPE& value)
    {
        vector<TYPE>::push_back(value); // 부모의 기능을 재사용
    }

    TYPE& top()
    {
        return vector<TYPE>::back();
    }

    void pop()
    {
        vector<TYPE>::pop_back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // 잘못된 사용
    // s.push_back(100); // !!

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
#endif

#include <stack>

#include <vector> // 연속된 메모리
#include <list> // 연결 리스트
#include <deque> // vector / list의 절충형 자료구조

// 재사용에서 "상속"보다는 "포함"이 좋습니다.
// => 상속은 재사용을 목적으로 하기 보다는, Upcasting을 기반으로 하는
//    "다형성"을 목적으로 해야 합니다.
//    : Clean Code

// => Design Pattern, 1995년
//    C++ Idioms

template <typename TYPE, typename C = deque<TYPE>>
class Stack {
    // vector<TYPE> v;
    C v;

public:
    void push(const TYPE& value)
    {
        v.push_back(value); // 부모의 기능을 재사용
    }

    TYPE& top()
    {
        return v.back();
    }

    void pop()
    {
        v.pop_back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // 잘못된 사용
    // s.push_back(100); // !!

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
