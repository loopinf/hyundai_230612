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

// version 3. 상태를 조작하는 함수와 상태를 하나의 타입으로 묶을 수 있습니다.
//     => 캡슐화(상태 + 행위)
//     => 상태와 행위를 가지고 있는 변수 => 객체

struct Stack {
    // 멤버 데이터(상태) / 속성(property)
    int buff[10];
    int top;

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

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
