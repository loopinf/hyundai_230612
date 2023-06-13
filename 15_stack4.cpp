// 15_stack3.cpp
#include <iostream>
using namespace std;

// 1. 객체의 상태는 멤버 함수를 통해서만 접근하거나, 수정될 수 있어야 합니다.
//     => 정보 은닉(Information Hiding)
//      : 접근 지정자
//       1) public: 외부에서 접근이 가능합니다.
//       2) private: 외부에서 접근이 불가능합니다. 오직 멤버 함수를 통해서만 접근이 가능합니다.

// 2. struct: 기본 접근 지정자가 public 입니다.
//    class : 기본 접근 지정자가 private 입니다.
//     > 객체를 설계할 때, 사용하는 사용자 정의 타입입니다.
//       : "클래스는 객체를 생성하는 틀입니다."

class Stack {
private:
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

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
