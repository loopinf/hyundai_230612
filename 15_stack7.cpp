// 15_stack7.cpp
#include <iostream>
using namespace std;

// 문제점
// -

class Stack {
    int* buff;
    int top;

public:
    Stack(int size = 10)
    {
        cout << "Stack(int)" << endl;
        buff = new int[size];
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

    Stack s1(100); // Stack(int)
    Stack s2; // Stack(int)

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
