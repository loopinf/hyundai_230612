// 33_예외.cpp
#include <iostream>
using namespace std;

int* foo()
{
    // 실패할 경우
    return nullptr;
}

int OpenFile(const char* filename)
{
    // 실패할 경우
    return -1;
}

// 1. C 에서는 함수의 성공/실패를 반환값을 통해 처리하는 경우가 많습니다.
// 2. 실패 가능한 함수는 반드시 오류 처리 해야 합니다.

// 반환값을 통한 오류 처리의 문제점
// 1) 오류 처리를 강제할 수 없습니다.
// 2) 반환값이 결과이지, 오류인지 모호할 수 있습니다.
//   : atoi

int main()
{
    int n = atoi("xxxxx10");
    cout << n << endl;

    int ret = OpenFile("a.txt");
    if (ret == -1) {
        // ...
    }
}
