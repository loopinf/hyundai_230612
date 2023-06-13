// 15_stack5.cpp
#include <iostream>
using namespace std;

class Stack {
    // 멤버 데이터(상태)
    int buff[10];
    int top;

public:
    // 멤버 함수(행위)
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

int main()
{
    Stack s1;
    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0; // 잘못된 접근
    // cout << s1.top << endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
