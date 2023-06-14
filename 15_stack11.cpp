// 15_stack11.cpp
#include <iostream>
using namespace std;

// C++ 언어
// => 멀티 패러다임 언어
//  객체 지향 / 함수형 / 일반적 프로그래밍

// 객체 지향 설계(Object Oriented Design)

// version 1. 전역 변수
//      > 여러개의 스택을 만들기 어렵습니다.
#if 0
int buff[10];
int top = 0;

void push(int n) { buff[top++] = n; }
int pop() { return buff[--top]; }

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
#endif

// version 2. 데이터 캡슐화 - 사용자 정의 타입
#if 0
struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s) { s->top = 0; }
void push(Stack* s, int n) { s->buff[(s->top)++] = n; }
int pop(Stack* s) { return s->buff[--(s->top)]; }

int main()
{
    Stack s1, s2;

    init(&s1);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}
#endif

#if 0
// version 3. 상태를 조작하는 함수와 상태를 하나의 타입으로 묶을 수 있습니다.
//     => 캡슐화(상태 + 행위)
//     => 상태와 행위를 가지고 있는 변수 => 객체

// 객체의 상태는 멤버 함수를 통해 관리되어야 합니다.
// 외부에서 함부로 접근하거나 변경할 수 없어야 합니다.
//  => 정보 은닉(Information Hiding)
//  => 접근 지정자
//   1) public: 외부에서 접근이 가능합니다.
//   2) private: 외부에서 접근이 불가능하고, 멤버 함수를 통해서만 접근이 가능합니다.

//  => C++에서 class는 기본 접근 지정자가 private 입니다.
//           struct는 기본 접근 지정자가 public 입니다.

//  => 클래스는 객체를 생성하는 틀 입니다.
class Stack {
private:
    // 멤버 데이터(상태) / 속성(property)
    int buff[10];
    int top;

public:
    // 멤버 함수(행위) / 메소드(method)
    void init() { top = 0; }
    void push(int n) { buff[top++] = n; }
    int pop() { return buff[--top]; }
};

int main()
{
    Stack s1, s2;

    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 100;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

#if 0
// version 4. 생성자 / 소멸자
//  - 생성자: 객체가 생성되는 시점에 호출되는 약속된 멤버 함수
//  - 소멸자: 객체가 파괴되는 시점에 호출되는 약속된 멤버 함수
//    > 객체 내부에서 자원(메모리, 파일, 락)을 할당하였을 때, 반드시 소멸자를 정의해서
//      자원을 해지해야 합니다.
class Stack {
private:
    int* buff;
    int top;

public:
    // Stack()
    // {
    //     top = 0;
    //     buff = new int[10];
    // }

    ~Stack()
    {
        delete[] buff;
    }

    Stack(int size = 10)
    {
        top = 0;
        buff = new int[size];
    }

    void push(int n) { buff[top++] = n; }
    int pop() { return buff[--top]; }
};

int main()
{
    Stack s1(100), s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

// version 5. 템플릿
//  => 모든 타입에 대해서 동작하는 스택을 만들 수 있습니다.
#if 0
template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(int size = 10)
    {
        top = 0;
        buff = new TYPE[size];
    }

    void push(TYPE n) { buff[top++] = n; }
    TYPE pop() { return buff[--top]; }
};

// 함수 템플릿은 인자를 통해, 템플릿의 타입을 컴파일러가 추론할 수 있습니다.
// 하지만 클래스 템플릿은 추론이 불가능한 경우가 많습니다.
//  => 명시적인 타입 지정

// 1. template <typename TYPE>
// class Stack
//  : Stack<int>, Stack<double>
//   - 타입 파라미터

// 2. template <typename T1, typename T2>
// class Stack
//  : Stack<int, double>
//    Stack<string, int>

int main()
{
    Stack<int> s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

// 표준 라이브러리에서 다양한 자료구조(컨테이너, 컬렉션)를 제공하고 있습니다.
#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // STL 컨테이너는 데이터를 제거하는 연산과, 참조하는 연산이 분리되어 있습니다.
    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
