// 15_stack3.cpp
#include <iostream>
using namespace std;

// 멤버 데이터(상태)와 멤버 데이터를 조작하는 함수(행위)를 하나의 타입으로 만들 수 있습니다.

struct Stack {
    // 멤버 데이터
    int buff[10];
    int top;

    // 멤버 함수
    void init()
    {
        top = 0;
    }

    void push(int n)
    {
        buff[top++] = n;
    }

    int pop()
    {
        return buff[--top];
    }
};

Stack s2;

int main()
{
    Stack s1;
    s1.init();
    s2.init();

    s1.push(10);
    s2.push(20);
    s2.push(30);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}
