// 21_복사생성자4.cpp
#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y) { }

    Point(const Point& rhs) { cout << "Point(const Point&)" << endl; }
    ~Point() { cout << "~Point()" << endl; }
};

template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        delete[] buff;
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};

int main()
{
}
