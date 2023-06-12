#include <iostream>

// calc.cpp
extern "C" int Add(int a, int b); // 선언부

int Add(int a, int b)
{
    std::cout << "C++ 함수입니다" << std::endl;
    return a + b;
}
// 0000000000000000 T _Add

// 0000000000000000 T __Z3Addii

int Add(int a, int b, int c) { return a + b + c; }
// 0000000000000020 T __Z3Addiii
