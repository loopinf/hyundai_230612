// 15_stack5.cpp
#include <iostream>
using namespace std;

// 문제점
// - 객체를 생성하였을 때, 바로 사용할 수 없습니다.

// 해결 방법
// - 객체가 생성되었을 때, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//   "생성자(Constructor) 함수"
// - 생성자: 객체의 상태를 초기화하는 역활을 담당합니다.
//    클래스이름()
//     1) 이름은 클래스(구조체)이름과 동일합니다.
//     2) 반환 타입도 없고, 명시하지도 않습니다.

class Stack {
    int buff[10];
    int top;

public:
    Stack()
    {
        cout << "Stack()" << endl;
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

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // s1.top = 0; // 잘못된 접근
    // cout << s1.top << endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
