// 29_가상함수의원리2.cpp
//  : 개념을 보기 위한 예제입니다.

#include <iostream>
using namespace std;

class AAA {
public:
    virtual void foo() { cout << "AAA foo" << endl; } // 1
};

// 상속 관계 아닙니다.
class BBB {
public:
    virtual void goo() { cout << "BBB foo" << endl; } // 2
};

int main()
{
    AAA aaa;

    BBB* p = reinterpret_cast<BBB*>(&aaa);
    // p는 BBB 타입이지만, aaa 객체를 참조합니다.

    p->goo();
    // p->vtptr[0](p);
}

#if 0
class AAA {
public:
    void foo() { cout << "AAA foo" << endl; } // 1
};

// 상속 관계 아닙니다.
class BBB {
public:
    void goo() { cout << "BBB foo" << endl; } // 2
};

int main()
{
    AAA aaa;

    BBB* p = reinterpret_cast<BBB*>(&aaa);
    // p는 BBB 타입이지만, aaa 객체를 참조합니다.

    p->goo();
    // 정적 바인딩: p의 타입 - BBB::goo(p);
}
#endif
