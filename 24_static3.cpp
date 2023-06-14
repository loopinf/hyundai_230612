// 24_static3.cpp
#include <iostream>
using namespace std;

// 1. 정적 멤버 데이터
//  > 전역 변수와 수명이 동일합니다. 클래스의 접근 제어가 가능합니다.
//    프로그램이 시작하기 전에 초기화되고, 프로그램이 종료될 때 파괴됩니다.
//    1) 객체를 생성하지 않아도, 접근할 수 있습니다.
//    2) 객체를 통해서도 접근할 수 있습니다.

// 2. 정적 멤버 함수
//  > 전역 함수와 동일합니다. 클래스의 접근 제어가 가능합니다.
//    1) 객체를 생성하지 않아도, 접근할 수 있습니다.
//    2) 객체를 통해서도 접근할 수 있습니다.

// 3. 멤버 데이터 / 멤버 함수
//  > 객체를 통해서만 접근이 가능합니다.

// 4. 멤버 함수는 this가 전달됩니다.
//  > 함수안에서 this가 필요한 멤버 데이터와 멤버 함수를 사용할 수 있습니다.
//  > 정적 멤버 데이터와 정적 멤버 함수 접근할 수 있습니다.

// 5. 정적 멤버 함수가 this가 전달되지 않습니다.
//  > 멤버 데이터와 멤버 함수를 접근할 수 없습니다.
//  > 정적 멤버 데이터와 정적 멤버 함수 접근할 수 있습니다.

#if 0
class Sample {
public:
    static int n; // 정적 멤버 데이터
    int data; // 멤버 데이터

public:
    Sample()
        : data(42)
    {
    }

    static void foo() // 정적 멤버 함수
    {
        cout << "Sample::foo" << endl;

        // cout << data << endl; // 에러! this가 없습니다.
        // hoo(); // 에러! this가 없습니다.
    }

    // void goo(Sample* this)
    void goo() // 멤버 함수
    {
        cout << "goo" << endl;

        cout << data << endl;
        //    this->data

        hoo(); // 다른 멤버 함수를 호출
        // this->hoo();
    }

    void hoo()
    {
        cout << "hoo" << endl;
    }
};

int Sample::n = 0; // 반드시 필요합니다.

int main()
{
    cout << Sample::n << endl;
    Sample::foo();

    cout << "-----------" << endl;
    Sample obj;
    cout << obj.data << endl;
    obj.goo();

    cout << "-----------" << endl;
    // 정적 멤버 데이터 / 멤버 함수는 객체를 통해서도 접근할 수 있습니다.
    cout << obj.n << endl;
    obj.foo();
}
#endif

class Sample {
    int data;

public:
    void foo() { }

    static void Func()
    {
        // data = 10; // this->data = 10;
        // foo(); // this->foo();
    }

    // 정적 멤버 함수에서 멤버 데이터와 멤버 함수에 접근하기 위해서는
    // 객체의 주소를 명시적으로 전달받으면 됩니다.
    static void Func(Sample* self)
    {
        self->data = 10;
        self->foo();
    }
};

int main()
{
    Sample s;
    Sample::Func(&s);
}
