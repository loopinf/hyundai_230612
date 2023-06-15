// 19_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    // 멤버 함수: 객체의 주소가 this를 통해 암묵적으로 전달됩니다.
    //  => thiscall

    // this: 멤버 함수에서 함수를 호출한 객체의 주소
    void Set(int a, int b)
    {
        x = a;
        y = b;

        this->x = a;
        this->y = b;
    }
    /*
    void Point::Set(Point* this, int a, int b)
    {
        this->x = a;
        this->y = b;
    }
    */
};

void Set(int a, int b)
{
}

int main()
{
    Set(10, 20);
    /*
    mov     edx, 20
    mov     ecx, 10
    call    void Set(int,int)
    */

    Point pt1, pt2;

    pt1.Set(10, 20); // Point::Set(&pt1, 10, 20);
    /*
    mov     r8d, 20                              ; r8d = 20
    mov     edx, 10                              ; edx = 10
    lea     rcx, QWORD PTR pt$[rsp]              ; rcx = &pt;

    call    void Point::Set(int,int)             ; Point::Set
    */

    pt2.Set(100, 300); // Point::Set(&pt2, 100, 300);
}
