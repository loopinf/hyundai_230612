// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
    int* buff;
    int top;

public:
    Stack(int size = 10);
    ~Stack();

    void push(int n);
    int pop();
};

#endif
