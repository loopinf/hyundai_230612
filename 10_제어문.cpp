// 10_제어문.cpp
#include <iostream>
using namespace std;

// 반복문 / 조건문
#if 0
int main()
{
    int x[5] = { 10, 20, 30, 40, 50 }; // 컨테이너, 자료구조

    for (int i = 0; i < 5; i++) {
        cout << x[i] << endl;
    }

    // C++11, ranged-for
    // : index 정보가 필요하지 않고, 요소의 값만 필요할 때
    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

// 실패할 경우, -1을 반환합니다.
int foo()
{
    return -1;
}

// 실패할 경우, NULL을 반환합니다.
int* goo()
{
    return NULL;
}

// 실패할 가능성이 있는 함수는 반드시 오류값을 체크해야 합니다.

// C++17, if-statement with initializer
//  if / switch 문에서도 사용할 수 있습니다.

enum {
    TASK_RUNNNING,
    TASK_STOPPED,
    TASK_WAIT
};

int GetCurrentState() { return TASK_WAIT; }

int main()
{
    switch (int state = GetCurrentState(); state) {
    case TASK_RUNNNING:
        cout << state << endl;
        break;
    case TASK_STOPPED:
        cout << state << endl;
        break;
    case TASK_WAIT:
        cout << state << endl;
        break;
    default:
        break;
    }

    double state = 3.14;

    if (int ret = foo(); ret == -1) {
        // 오류 처리
    }

    if (int* ret = goo(); ret == NULL) {
        // 오류 처리
    }
}

#if 0
int main()
{
    for (int i = 0; i < 10; i++) { };
    for (int i = 0; i < 10; i++) { };

    int ret = foo();
    if (ret == -1) {
        // 오류 처리
    }

    int* ret2 = goo();
    if (ret2 == NULL) {
        // 오류 처리
    }
}
#endif
