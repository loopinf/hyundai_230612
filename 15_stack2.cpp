// 15_stack2.cpp
#include <iostream>
using namespace std;

// 하나의 프로그램에 여러 개의 스택을 제공하기 어렵습니다.
// => 스택의 상태(buff, top)를 전역 변수가 아닌,
//    사용자 정의 타입(구조체)를 통해 캡슐화합니다.
//    : 데이터 캡슐화

struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s)
{
    s->top = 0;
}

void push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int pop(Stack* s)
{
    return s->buff[--(s->top)];
}

Stack s2;

int main()
{
    Stack s1;
    init(&s1);
    init(&s2);

    push(&s1, 10);
    push(&s2, 20);
    push(&s2, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
    cout << pop(&s2) << endl;
}
