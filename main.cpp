// main.cpp
#include <iostream>
using namespace std;

extern "C" int Add(int a, int b);
// U _Add

// int Add(int a, int b);
// U __Z3Addii

int main()
{
    cout << Add(10, 20) << endl;
}

// g++ -c main.cpp
