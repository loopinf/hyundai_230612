// 2_namespace3.cpp
#include <iostream>

// #include <stdio.h>
#include <cstdio>
// C++ 표준 헤더를 통해 C의 헤더를 포함하는 것이 좋습니다.

int main()
{
    std::printf("Hello, C\n");
    // C++에서 제공하는 C의 모든 함수는 std 이름 공간 안에서 사용할 수 있습니다.

    std::cout << "Hello, C++" << std::endl;
}
