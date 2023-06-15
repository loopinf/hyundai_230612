// 21_복사생성자4.cpp
#include <iostream>
using namespace std;

class Point {
public:
    Point() { }

    Point(const Point& rhs) { cout << "Point(const Point&)" << endl; }
    // ~Point() { cout << "~Point()" << endl; }
};

template <typename TYPE>
class Stack {
    TYPE* buff_;
    int top_;

public:
    Stack(int size = 10)
    {
        buff_ = new TYPE[size];
        top_ = 0;
    }

    ~Stack()
    {
        delete[] buff_;
    }

    // void push(TYPE n)           => void push(Point n)
    //                             => void push(int n)

    // void push(const TYPE& n)    => void push(const Point& n)
    //                                void push(const int& n)

// 아래 함수는 참조를 반환할 수 없습니다.
// 스택에서 제거되는 영역에 대한 참조를 반환하면 안됩니다.
//  - 해결 방법: 참조하는 연산과 제거하는 연산을 분리해야 합니다.
#if 0
    void push(TYPE n)
    {
        buff_[top_++] = n;
    }

    TYPE pop()
    {
        return buff_[--top_];
    }
#endif

#if 1
    void push(const TYPE& n)
    {
        buff_[top_++] = n;
    }

    TYPE& top()
    {
        return buff_[top_ - 1];
    }

    void pop()
    {
        --top_;
    }
#endif
};

int main()
{
    Stack<Point> s;

    Point pt;

    cout << "-----------" << endl;
    s.push(pt);
    cout << "-----------" << endl;

    cout << "-----------" << endl;
    s.top();
    s.pop();
    cout << "-----------" << endl;
}

// C++ 추천 서적
// - Effective C++, 스콧 마이어스
//   Effective Modern C++

// C++
//  크로미움, AOSP
