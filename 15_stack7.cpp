// 15_stack7.cpp
#include <iostream>
using namespace std;

// 문제점
// - 객체 내부에서 메모리를 할당한다면, 반드시 객체가 파괴될 때
//   해지해야 합니다.

// 해결 방법
// - 객체가 파괴되는 시점에 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//   소멸자(Destructor) 함수
//    : ~클래스이름()
//    1) 소멸자의 이름은 ~클래스이름() 입니다.
//    2) 반환값도 없고, 명시하지도 않습니다.
//    3) 소멸자는 인자가 없습니다.
//    4) 소멸자는 1개만 정의 가능합니다. 오버로딩이 불가능합니다.
//   => 클래스가 자원을 할당했다면, 반드시 소멸자를 정의해서
//      자원을 정리해야 합니다.

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

    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
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
