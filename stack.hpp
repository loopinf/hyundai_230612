// stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

template <typename TYPE>
class Stack {
    TYPE* buff;
    int top;

public:
    Stack(int size = 10);

    ~Stack();

    void push(TYPE n);

    TYPE pop();
};

//       Stack: 템플릿
// Stack<TYPE>: 클래스

template <typename TYPE>
Stack<TYPE>::Stack(int size)
{
    buff = new TYPE[size];
    top = 0;
}

template <typename TYPE>
Stack<TYPE>::~Stack()
{
    delete[] buff;
}

template <typename TYPE>
void Stack<TYPE>::push(TYPE n)
{
    buff[top++] = n;
}

template <typename TYPE>
TYPE Stack<TYPE>::pop()
{
    return buff[--top];
}

#endif
