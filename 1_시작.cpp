// 1_시작.cpp

// Visual Studio
// - Compile: Ctrl + F7
// - Compile + Linking + Run: Ctrl + F5

// 1. C++ 확장자
//  .cpp / .cc / .cxx ...

// 2. C++ 컴파일러
// - MSVC, Microsoft Visual C/C++ Compiler
// - GCC, GNU C/C++ Compiler
// - LLVM, clang

// 3. C++ 표준
//  C++98/03 => 1차 표준안
//  C++11/14 => 2차 표준안, Modern C++
//  C++17/20 => 3차 표준안

// 4. C++은 C 문법을 지원합니다.
//  => C의 표준과 C++ 안에서의 C의 표준은 다릅니다.

#if 0
#include <stdio.h>

int main(void)
{
	printf("Hello, C\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo(void) {}
void goo() {}

int main()
{
	printf("Hello, C++\n");
	
	// C++ 컴파일러가 main의 마지막에 return 0를 자동으로 삽입해줍니다.
}
#endif

#if 0
// C++에도 표준 입출력 라이브러리가 제공됩니다.
#include <iostream>
// > .h 확장자가 사용되지 않습니다.

// Input/Output Stream

int main()
{
	std::cout << "Hello, C++" << std::endl;
}
#endif

// #define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(void)
{
	double n;
	scanf("%lf", &n);

	printf("n: %lf\n", n);
	return 0;
}
#endif

#if 1
#include <iostream>

// 1) 서식을 사용하지 않습니다.
//    변수의 타입에 따라 원하는 형태로 입출력이 수행됩니다.
//   => 함수 오버로딩

// 2) 변수의 주소를 전달하지 않아도, 변수의 값을 변경할 수 있습니다.
//   => 레퍼런스, Call by reference

// 3) std::cin / std::cout / std::endl
//  > 어떤 원리로 구현되어 있을까요?
//  => std::cin / std::cout
//    - 연산자 오버로딩과 함수 오버로딩

int main()
{
    double n;
    std::cin >> n;

    std::cout << "n: " << n << std::endl;
}
#endif
