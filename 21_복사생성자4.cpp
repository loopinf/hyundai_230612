// 21_복사생성자4.cpp
#include <iostream>
using namespace std;

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
