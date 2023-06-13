// stack.cpp
#include "stack.h"

Stack::Stack(int size = 10)
{
    buff = new int[size];
    top = 0;
}

Stack::~Stack()
{
    delete[] buff;
}

void Stack::push(int n)
{
    buff[top++] = n;
}

int Stack::pop()
{
    return buff[--top];
}
