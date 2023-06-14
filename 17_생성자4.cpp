// 17_생성자4.cpp

#include <iostream>
using namespace std;

class Object {
public:
    Object() { cout << "Object()" << endl; }
    ~Object() { cout << "~Object()" << endl; }
};

// 객체의 수명
//  - 전역 객체
//    : 프로그램이 시작할 때, 생성자가 호출되고,
//      프로그램이 종료되기 전에 소멸자가 호출됩니다.

//  - 지역 객체
//    : 범위의 시작에 생성자가 호출되고,
//      범위의 종료에 소멸자가 호출됩니다.

//  - 정적 지역 객체
//    : 함수가 최초에 실행되는 시점에 초기화되고,
//     함수가 더 이상 호출되지 않을때(프로그램의 종료 시점)에
//     소멸자가 호출됩니다.

//  - 동적 메모리 할당(힙 객체)
//    : new를 하였을 때 생성자가 호출되고,
//      delete를 하였을 때, 소멸자가 호출됩니다.

void foo()
{
    cout << "foo 함수 시작" << endl;
    static Object obj2;
    cout << "foo 함수 종료" << endl;
}

Object obj1;

int main()
{
    cout << "main 시작" << endl;

    {
        Object obj2;
    }

    foo();
    foo();
    foo();

    cout << "main 종료" << endl;
}
