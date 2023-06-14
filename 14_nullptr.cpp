// 14_nullptr.cpp
#include <iostream>
using namespace std;

// 1. 정수값 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
// 2. NULL
//    - #define NULL (void*)0

// 3. NULL 문제점
//   => 정수인지 포인터 타입인지 모호합니다.
//    - 타입 안정성 문제

// 4. C++11에서 NULL을 대체하는, nullptr 도입되었습니다.

// 5. nullptr의 정확한 타입은 nullptr_t 타입입니다.
//  => 포인터 타입으로의 암묵적인 변환을 허용합니다.
//     nullptr은 bool 타입으로의 암묵적인 변환을 허용합니다.

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

#if 0
int main()
{
    cout << sizeof(bool) << endl;
    bool b = true;
    b = false;
    printf("%d\n", true);
    printf("%d\n", false);

    int* p1 = nullptr;

    foo(0);
    foo(nullptr);

    // if (!NULL) {
    if (!nullptr) {
        cout << "NULL은 FALSE 입니다." << endl;
    }
}
#endif

#if 0
int main()
{
    int* p1 = NULL;
    int* p2 = 0; // OK, 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.

    // int* p3 = 100; // Error!, 0이 아닌 정수는 허용되지 않습니다.

    foo(0);
    // foo(NULL); // Error!, NULL은 0인지 포인터인지 모호합니다.
}
#endif
