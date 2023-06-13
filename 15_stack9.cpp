// 15_stack9.cpp
#include <iostream>
using namespace std;

// 문제점
// => 다양한 타입을 저장하는 스택을 만들고 싶습니다.

// 해결방법
// => 클래스도 템플릿으로 만들 수 있습니다.

// 클래스 템플릿
// => 클래스 템플릿을 헤더와 소스코드로 분리하는 것은 불가능합니다.
// => 템플릿은 헤더(선언 + 구현)를 통해서만 제공 가능합니다.
//    : 확장자를 hpp(.h + .cpp)를 많이 사용합니다.
#if 0
template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        delete[] buff;
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};
#endif

#include "stack.hpp" // 헤더 파일

#include <string>
int main()
{
    Stack<string> s1(100); // Stack(int)
    // TYPE -> string

    s1.push("hello");
    s1.push("world");
    s1.push("good");

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}

#if 0
// 클래스 템플릿은 타입 추론이 어렵습니다.
// => 명시적으로 타입을 지정해야 하는 경우가 많습니다.
int main()
{
    Stack<double> s1(100); // Stack(int)
    // TYPE -> double

    s1.push(3.14);
    s1.push(20.5);
    s1.push(30.1);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif
