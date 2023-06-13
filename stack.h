// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
    int* buff;
    int top;

public:
    Stack(int size = 10);
    ~Stack();

    inline void push(int n);
    inline int pop();
};

// 인라인 함수의 구현은 소스 파일이 아닌
// 헤더 파일에 제공되어야 합니다.
void Stack::push(int n)
{
    buff[top++] = n;
}

int Stack::pop()
{
    return buff[--top];
}

inline void foo()
{
    // ...
}

#endif
