// 2_namespace3.cpp
#include <iostream>

// #include <stdio.h>
#include <cstdio>
// C++ 표준 헤더를 통해 C의 헤더를 포함하는 것이 좋습니다.

#include <cstdlib>
#include <cstring>
#include <cctype>

/*
int main()
{
    std::printf("Hello, C\n");
    // C++에서 제공하는 C의 모든 함수는 std 이름 공간 안에서 사용할 수 있습니다.

    std::cout << "Hello, C++" << std::endl;
}
*/

#include <algorithm>
// std::count 함수가 이 안에 존재합니다.

// using namespace std;
using std::cout;
using std::endl;

int count = 0;

int main()
{
    count = 100;

    cout << "Hello, C++" << endl;
}
