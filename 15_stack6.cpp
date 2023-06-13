// 15_stack6.cpp
#include <iostream>
using namespace std;

// 문제점
// - 사용자가 원하는 크기의 스택을 생성하고 싶습니다.

// 해결방법
// - 생성자의 인자를 통해 크기를 전달하면 됩니다.
// - 생성자는 오버로딩이 가능합니다.
//   : 객체를 생성하는 다양한 옵션을 제공할 수 있습니다.

class Stack {
    int* buff;
    int top;

public:
#if 0
    Stack()
    {
        cout << "Stack()" << endl;
        buff = new int[10];
        top = 0;
    }

    Stack(int size)
    {
        cout << "Stack(int)" << endl;
        buff = new int[size];
        top = 0;
    }
#endif
    // 파라미터 기본값을 통해 불필요한 오버로딩을 제거할 수 있습니다.
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
