// 15_stack.cpp
#include <iostream>
using namespace std;

// 스택: LIFO(Last In First Out)

// 1. 전역 변수
int buff[10];
int top = 0;

void push(int n)
{
    buff[top++] = n;
}

int pop()
{
    return buff[--top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
