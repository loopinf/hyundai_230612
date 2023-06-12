// main.c
#include <stdio.h>

int Add(int a, int b);
// U _Add

int main(void)
{
    int result = Add(10, 20);
    printf("result: %d\n", result);

    return 0;
}

// main.c      calc.cpp
//             extern "C" int Add(int a, int b) {}

// main.cpp                              calc.c
// extern "C" int Add(int a, int b);
